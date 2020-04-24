#include "stdafx.h"
#include "PNcalculation.h"

PNCalculation::PNCalculation(char* Inputstr)
{
	this->Inputstr = Inputstr;
	strsize = this->Inputstr.size();
	result = 0;
}

PNCalculation::~PNCalculation()
{
}

void PNCalculation::calculator()
{
	changestr = new char[strsize + 1];
	
	strcpy(changestr, Inputstr.c_str());

	for (size_t i = 0; i < strsize; i++)
	{
		if (isdigit(changestr[i]))
		{
			stack.Push(changestr[i]);
		}
		else
		{
			switch (changestr[i])
			{
				case '+':
				{
					int second = stack.Pop() - '0';
					int  first = stack.Pop() - '0';

					result = first + second + '0';
					stack.Push(result);
					break;

				}

				case '-':
				{
					int second = stack.Pop() -'0';
					int  first = stack.Pop() -'0';

					result = first - second + '0';
					stack.Push(result);
					break;

				}

				case '*':
				{
					int second = stack.Pop() - '0';
					int  first = stack.Pop() - '0';

					result = first * second + '0';
					stack.Push(result);
					break;

				}

				case '/':
				{
					int second = stack.Pop() - '0';
					int  first = stack.Pop() - '0';

					result = first / second + '0';
					stack.Push(result);
					break;
				}

			}

		}
	}
}
