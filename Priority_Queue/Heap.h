#pragma once
#include <iostream>

using namespace std;
#define DATA_LEN	100
typedef int Hdata;

 class Heap
{
public:
	void Hinit(Heap *hp);
	bool Hempty(Heap *hp);
	void Hinsert(Heap *hp, Hdata data);
	Hdata Hdelete(Heap *hp);
	int getcountdata() { return countdata; }
	void setcountdata(int data) { this->countdata -= data; }
	int PriorityComp(Hdata d1, Hdata d2);
	Hdata getdata(int index) { return data[index]; }
	void setdata(int index, int data) { this->data[index] = data; }

private:
	Hdata data[DATA_LEN] = { 0, };
	int countdata;

};