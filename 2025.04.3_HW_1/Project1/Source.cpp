#include<iostream>

class ArrayList
{ //àáñòðàêöèÿ, èíêàïñóëÿöèÿ
private:
	int len;
	int* data;
	void init(int len)
	{
		//(*this).len = len;
		this->len = len;
		this->data = (int*)malloc(sizeof(int) * len);
	}
	bool indexValid(int index)
	{
		return 0 <= index < this->len;
	}

public:
	ArrayList(int len)
	{
		this->init(len);
		for (int i = 0; i < this->len; ++i)
		{
			this->data[i] = 0;
		}
	}
	ArrayList(ArrayList& list)
	{
		//this->len = list.len;
		//this->data = list.data;
		this->init(list.len);
		for (int i = 0; i < list.len; ++i)
		{
			this->set(i, list.get(i));
		}
	}
	~ArrayList()
	{
		//for (int i = 0; i < this->len; ++i)
		//{
		//	this->data[i] = 0;
		//}
		free(this->data);
		//this->data = nullptr;
		//this->len = 0;
	}
	void randomize(int min = 1, int max = 9)
	{
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = rand() % (max - min + 1) + min;
		}
	}
	void print()
	{
		for (int i = 0; i < this->len; ++i)
		{
			printf("%d ", this->data[i]);
		}
		printf("\n");
	}
	int get(int index)
	{
		if (indexValid(index))
		{
			return this->data[index];
		}
		return -1;
	}
	void set(int index, int value)
	{
		if (indexValid(index))
		{
			this->data[index] = value;
		}
	}
	int count()
	{
		return len;
	}
	int changeLen(int newlen)
	{
		len = newlen;
		return newlen;
	}
	void pushBack(int element)
	{
		int* s = (int*)malloc(sizeof(int) * (len + 1));
		for (int i = 0; i < len; ++i)
		{
			s[i] = this->data[i];
		}
		s[len] = element;
		init(len + 1);
		for (int i = 0; i < len + 1; ++i)
		{
			this->data[i] = s[i];
		}
	}
	void pushFront(int element)
	{
		int* s = (int*)malloc(sizeof(int) * (len + 1));
		for (int i = 0; i < len + 1; ++i)
		{
			s[i + 1] = this->data[i];
		}
		s[0] = element;
		init(len + 1);
		for (int i = 0; i < len + 1; ++i)
		{
			this->data[i] = s[i];
		}
	}
	void insert(int index, int element)
	{
		this->data[index] = element;
	}
	void popBack()
	{
		int* s = (int*)malloc(sizeof(int) * (len - 1));
		for (int i = 0; i < len - 1; ++i)
		{
			s[i] = this->data[i];
		}
		int newlen = changeLen(len - 1);
		this->data = s;
	}
	void popFront()
	{
		int* s = this->data;
		init(len - 1);
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = s[i + 1];
		}
	}
	void extract(int index)
	{
		int* suparr = (int*)malloc(sizeof(int) * (len));
		for (int i = 0; i < len; ++i)
		{
			suparr[i] = this->data[i];
		}
		init(len - 1);
		for (int i = 0; i < index; ++i)
		{
			this->data[i] = suparr[i];
		}
		for (; index < len; ++index)
		{
			this->data[index] = suparr[index + 1];
		}

	}
	void reverse(int start, int end)
	{
		int* s = (int*)malloc(sizeof(int) * len);
		for (int i = 0; i < len; ++i)
		{
			s[i] = this->data[i];
		}
		for (int i = 0; i < len; ++i)
		{
			this->data[i] = s[len - 1 - i];
		}
	}
	int sum()
	{
		int sum = 0;
		for (int i = 0; i < len; ++i)
		{
			sum += this->data[i];
		}

		return sum;
	}
	int secondMax()
	{
		int firstmax = data[0];
		for (int i = 1; i < len; ++i)
		{
			if (this->data[i - 1] << this->data[i])
			{
				firstmax = this->data[i];
			}
		}

		int secondmax = data[0];
		for (int i = 1; i < len; ++i)
		{
			if (this->data[i - 1] << this->data[i] && this->data[i] != firstmax)
			{
				secondmax = this->data[i];
			}
		}

		return secondmax;
	}
	int lastMinIndex()
	{
		int lastminind = 0;
		for (int i = 1; i < len; ++i)
		{
			if (this->data[i - 1] > this->data[i])
			{
				lastminind = i;
			}
		}

		return lastminind;
	}
	void shift(int k)
	{
		int* memarr = (int*)malloc(sizeof(int) * len);
		for (int i = 0; i < len; ++i)
		{

			memarr[len - 1 - i] = this->data[len - 1 - (i + k) % len];
		}
		for (int i = 0; i < len; ++i)
		{

			this->data[i] = memarr[i];
		}
	}
	int countOdd()
	{
		int countOdd = 0;
		for (int i = 0; i < len; ++i)
		{
			if (this->data[i] % 2 == 1)
			{
				++countOdd;
			}
		}

		return countOdd;
	}
	int sumEven()
	{
		int sumev = 0;
		for (int i = 0; i < len; ++i)
		{
			if (this->data[i] % 2 == 0)
			{
				sumev += this->data[i];
			}
		}

		return sumev;
	}
};


int max(ArrayList list)
{
	int mx = list.get(0);
	for (int i = 0; i < list.count(); ++i)
	{
		mx = (mx > list.get(i) ? mx : list.get(i));
	}
	return mx;
}

int main(int argc, char* argv[])
{
	ArrayList list(10);
	list.randomize();
	list.print();
	list.extract(8);
	list.print();
	return 0;
}