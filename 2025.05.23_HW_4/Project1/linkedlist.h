#pragma once
#include<iostream>

struct Node
{
	int data;
	Node* next;
	Node(int data = 0, Node* next = nullptr) :
		data(data), next(next)
	{}
	~Node()
	{
		next = nullptr;
	}
};

class linkedlist
{
private:
	Node* head;
	Node* extractHeadNode();

public:
	linkedlist() :
		head(nullptr)
	{}
	~linkedlist();
	bool isEmpty();
	void print();
	int get(int index);
	void set(int index, int value);
	void pushBack(int element);
	void pushFront(int element);
	void insert(int index, int element);
	int popBack();
	int popFront();
	int extract(int index);
};
