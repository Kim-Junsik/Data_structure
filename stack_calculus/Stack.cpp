#include "stdafx.h"
#include "Stack.h"

Stack::Stack()
{
	TopofArr = -1;
	for (size_t i = 0; i < 100; i++)
	{
		StackArr[i] = { NULL, };
	}
}

Stack::~Stack()
{

}

bool Stack::IsEmpty()
{
	if (TopofArr >= 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}

char Stack::Peek()
{
	if (!IsEmpty())
	{
		return StackArr[TopofArr];
	}
	else
	{
		cout << "잘못된 접근입니다." << endl;
		return -1;
	}
}

void Stack::Push(char Data)
{
		TopofArr += 1;
		StackArr[TopofArr] = Data;
}

char Stack::Pop()
{
	if (!IsEmpty())
	{
		char ReturnData = StackArr[TopofArr];
		TopofArr -= 1;

		return ReturnData;
	}
	else
	{
		cout << "잘못된 접근입니다." << endl;
	}
	return NULL;
}

char Stack::GetData()
{
	int result = StackArr[TopofArr] - 0;
	return result;
}
