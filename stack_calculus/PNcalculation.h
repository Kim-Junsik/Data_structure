#pragma once
#include "stdafx.h"
#include "Change_postfixNotation.h"
#include "Stack.h"

class PNCalculation
{
public:
	PNCalculation(char* Inputstr);
	~PNCalculation();


	void calculator();
	int GetData() { return stack.GetData(); }
private:
	string Inputstr;
	char* changestr;
	Stack stack;

	int strsize;
	char result;

};