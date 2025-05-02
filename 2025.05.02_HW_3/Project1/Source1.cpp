
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib> 

using namespace std;

struct Student {
    string name;
    int hp;
    int dmg;
    int luck;

    Student() : name(""), hp(0), dmg(0), luck(0) {}
    Student(string name, int hp, int dmg, int luck)
        : name(name), hp(hp), dmg(dmg), luck(luck) {}

    bool luckWorks() const {
        return (rand() % 100 < luck);
    }

    bool isDead() const {
        return hp <= 0;
    }


    void getDmg(int dmg)
    {
        if (luckWorks())
        {
            cout << "\t" << name << " LUCK WORKS FOR GETTING DAMAGE\n";
            dmg /= 2;
        }
        hp -= dmg;
    }

    int makeDmg() const {
        if (luckWorks()) {
            cout << "\t" << name << " double damage!\n";
            return dmg * 2;
        }
        return dmg;
    }

    void print() {
        cout << name << " [HP=" << hp << ", DMG=" << dmg << ", LUCK=" << luck << "]";
    }
};


Student battle(Student st1, Student st2) {
    int round = 1;
    cout << "=== " << st1.name << " vs " << st2.name << " ===\n";
    while (!st1.isDead() && !st2.isDead()) {
        cout << "--- Round " << round++ << " ---\n";
        st1.print();
        cout << " vs ";
        st2.print();
        cout << "\n";
        int d1 = st1.makeDmg();
        int d2 = st2.makeDmg();
        st2.getDmg(d1);
        st1.getDmg(d2);
        
        if (st1.name == "Edgar" && rand() % 100 < 20) {
            int heal = st1.dmg;
            st1.getDmg(-heal);
        }
        cout << "\n";
    }
    if (st1.isDead() && st2.isDead()) {
        cout << "DRAW\n\n";
        return Student();
    }
    Student winner = st1.isDead() ? st2 : st1;
    cout << "Result: " << winner.name << " wins!\n\n";
    return winner;
}


void tournament(Student players[], int count) {
    cout << "=== Tournament ===\n";
    
    for (int i = count - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Student temp = players[i];
        players[i] = players[j];
        players[j] = temp;
    }

    int round = 1;
    Student nextRound[100];
    int currentCount = count;
    while (currentCount > 1) {
        cout << "-- Round " << round++ << " --\n";
        int nextCount = 0;
        for (int i = 0; i + 1 < currentCount; i += 2) {
            nextRound[nextCount++] = battle(players[i], players[i + 1]);
        }
        
        if (currentCount % 2 == 1) {
            
            nextRound[nextCount++] = players[currentCount - 1];
        }
       
        for (int i = 0; i < nextCount; ++i) {
            players[i] = nextRound[i];
        }
        currentCount = nextCount;
    }
    if (currentCount == 1 && players[0].name != "") {
        cout << "=== Winner " << players[0].name << " ===\n";
    }
    else {
        cout << "=== No winner ===\n";
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Student players[] = {
        {"BOBA", 150, 5, 0},
        {"BIBA", 60, 10, 30},
        {"Edgar", 80, 8, 25},
        {"Mamoshin", 120, 6, 15},
        {"Sheshukov", 100, 7, 20}
    };
    int count = sizeof(players) / sizeof(players[0]);
    tournament(players, count);
    return 0;
}