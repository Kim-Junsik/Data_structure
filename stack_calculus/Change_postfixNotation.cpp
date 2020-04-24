#include "stdafx.h"
#include "Change_postfixNotation.h"

postfixNotation::postfixNotation(string Input)
{
	InputString = Input;	//입력받은 문자열 저장(원본)
	int InputStringsize = InputString.size();

	Equation = new char[InputStringsize + 1];		//변경할 문자 저장 배열

	for (size_t i = 0; i < InputStringsize + 1; i++)
	{
		Equation[i] = { NULL, };
	}

	strcpy(Equation, InputString.c_str());		//문자열을 문자로 변경 후 복사 
	ChangEquation = new char[InputStringsize +1];	//변경된 문자 저장
	for (size_t i = 0; i < InputStringsize + 1; i++)
	{
		ChangEquation[i] = { NULL, };
	}

}

postfixNotation::~postfixNotation()
{
	delete []Equation;
	delete []ChangEquation;
}

char* postfixNotation::change()
{
	for (size_t i = 0; i < (InputString.size()); i++)
	{
		if (isdigit(Equation[i]))
		{
			ChangEquation[ChangEquationIdx] = Equation[i];
			ChangEquationIdx++;
		}
		else
		{
			switch (Equation[i])
			{
			case '(':
				stack.Push(Equation[i]);
				break;
			case ')':
				{
					while (1)
					{
						char temp = stack.Pop();
						if (temp == '(')
						{
							break;
						}
						ChangEquation[ChangEquationIdx++] = temp;
					}

				}

				break;
			case '+': case'-':
			case '*': case'/':
				if (stack.IsEmpty())
				{
					stack.Push(Equation[i]);
				}
				else
				{
					//while (!stack.IsEmpty())
					//{
					char cmpChar = stack.Pop();
					int cmpresult = Priority(cmpChar, Equation[i]);		//앞이 클 경우 1, 작을 경우 -1, 같을 경우 0

					if (cmpresult > 0)
					{
						ChangEquation[ChangEquationIdx] = cmpChar;
						stack.Push(Equation[i]);
						ChangEquationIdx++;
					}
					else if (cmpresult == 0)
					{
						stack.Push(Equation[i]);
					}
					else if (cmpresult < 0)
					{
						stack.Push(cmpChar);
						stack.Push(Equation[i]);
					}
					//}
				}

				break;
			}


		}
	}

	while(stack.getTOS()>=0)
	{
		ChangEquation[ChangEquationIdx] = stack.Pop();
		ChangEquationIdx++;
	}

	return ChangEquation;
}

int postfixNotation::Priority(char cmpChar, char Equation)
{
	int RcmpChar = INTPriority(cmpChar);
	int REquation = INTPriority(Equation);

	if (RcmpChar > REquation)
	{
		return 1;
	}
	else if (RcmpChar < REquation)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int postfixNotation::INTPriority(char text)
{
	switch (text)
	{
	case '*':
	case '/':
		return 3;

	case '+':
	case '-':
		return 2;

	case '(':
		return 1;

	}
}
