#pragma once
#include <iostream>
#include <string>

using namespace std;

//초기화시 배열 동적할당

class Priority
{
private:
	string *m_data;
	int *m_length;
	int m_countdata;
public:
	Priority(int size);
	~Priority();

	void Insert(string data);
	string Delete();
	
	int getHiChildIndex(int index);
	string getData(int index);
	void setData(int index, string data);
	int getlength(int index);
	int getparentIndex(int index);
	int getleftindex(int index);
	int getrightindex(int index);
	bool empty();
	int PriorityComp(int length1, int length2);

};