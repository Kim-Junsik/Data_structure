#pragma once
#include "stdafx.h"
#include "Stack.h"

#define Change_postfixNotation postfixNotation;

using namespace std;

class Stack;
class postfixNotation
{
public:
	postfixNotation(string Input);
	~postfixNotation();

	//void Init();							//�ʱ�ȭ �Լ�
	char* change();							//������ ���� �Լ�
	int Priority(char , char);				//�켱���� Ȯ�� �Լ�
	int INTPriority(char);					//�켱���� ���� �Լ�

private:
	Stack stack;					//������ ���������� �����ϱ����� ����
	string InputString;				//�Է¹޴� ����
	char *Equation;					//�Է¹��� ������ �������� �Ҵ��Ͽ� ������
	char *ChangEquation;			//���������� ������ ���ڿ�(��ȯ��)->�����Ҵ�

	int ChangEquationIdx = 0;
};
