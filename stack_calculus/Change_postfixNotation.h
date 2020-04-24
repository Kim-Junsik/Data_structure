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

	//void Init();							//초기화 함수
	char* change();							//후위식 변경 함수
	int Priority(char , char);				//우선순위 확인 함수
	int INTPriority(char);					//우선순위 정보 함수

private:
	Stack stack;					//수식을 후위식으로 변형하기위한 스택
	string InputString;				//입력받는 수식
	char *Equation;					//입력받은 수식을 동적으로 할당하여 재저장
	char *ChangEquation;			//후위식으로 변경한 문자열(반환값)->동적할당

	int ChangEquationIdx = 0;
};
