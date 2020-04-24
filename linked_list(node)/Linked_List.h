#pragma once
#include <iostream>


class Node
{
public:
	Node();
	~Node() {};
	void Linked(Node* Head, int Data);
	Node* CreateNode(int);
	void Detele(Node*, int);
	void Sort(Node*);
	void DataCmp(int, int);
	void Insert(Node*, int, int);
	void Print(Node*, int);
private:
	int Data;
	int Count;
	Node *Next;
};
