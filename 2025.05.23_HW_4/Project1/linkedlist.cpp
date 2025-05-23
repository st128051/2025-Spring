#include "linkedlist.h"

linkedlist::~linkedlist()
{
	while (!isEmpty())
	{
		delete extractHeadNode();
	}
}

bool linkedlist::isEmpty()
{
	return (head == nullptr);
}

void linkedlist::pushBack(int element)
{
	if (isEmpty())
	{
		return pushFront(element);
	}
	//(*head).next
	//  head->next
	Node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = new Node(element);
}

void linkedlist::pushFront(int data)
{
	head = new Node(data, head);
	//Node* newhead = new Node(data);
	//newhead->next = head;
	//this->head = newhead;
}

Node* linkedlist::extractHeadNode()
{
	Node* temp = head;
	if (head != nullptr)
	{
		head = head->next;
	}
	return temp;
}

int linkedlist::popBack()
{
	if (isEmpty())
	{
		return 0;
	}
	if (head->next == nullptr)
	{
		return popFront();
	}
	Node* temp = head;
	while (temp->next->next != nullptr) //äîøëè äî ïðåäïîñëåäíåé íîäû
	{
		temp = temp->next;
	}
	int res = temp->next->data;
	delete temp->next;
	temp->next = nullptr;
	return res;
}

int linkedlist::popFront()
{
	if (head == nullptr)
	{
		return 0;
	}
	Node* temp = extractHeadNode();
	int res = temp->data;
	delete temp;
	return res;
}

void linkedlist::print()
{
	Node* temp = this->head;
	if (temp == nullptr)
	{
		std::cout << "EMPTY";
	}
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

int linkedlist::get(int index) {
	Node* curr = head;
	int i = 0;
	while (curr && i < index) {
		curr = curr->next;
		 ++i;
	}
	return curr->data;
}

void linkedlist::set(int index, int value) {
	Node* curr= head;
	int i = 0;
	while(curr && i < index) {
		curr = curr->next;
		++i;
	}
	curr->data = value;
}

void linkedlist::insert(int index, int element) {
	if (index == 0) {
		head = new Node(element, head);
		return;
	}
	Node* curr =head;
	int i = 0;
	while (curr && i < index - 1) {
		curr = curr->next;
		++i;
	}
	curr->next = new Node(element, curr->next);
}

int linkedlist::extract(int index) {
	if (index == 0) {
		Node* node = extractHeadNode();
		int val = node->data;
		delete node;
		return val;
	}
	Node* curr = head;
	int i = 0;
	while (curr->next &&i < index-1) {
		curr= curr->next;
		++i;
	}
	Node* node = curr->next;
	curr->next = node->next;
	int val = node->data;
	delete node;
	return val ;
}
