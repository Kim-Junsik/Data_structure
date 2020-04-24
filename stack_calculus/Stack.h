#pragma once
#include "stdafx.h"
using namespace std;

class Stack
{
public:
	Stack();
	~Stack();

	bool IsEmpty();
	char Peek();
	void Push(char Data);
	char Pop();
	char GetData();

	int getTOS() { return TopofArr; }

private:
	char StackArr[100];
	int TopofArr;
};