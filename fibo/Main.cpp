#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
using namespace std;

uint64_t Fibonum[200] = { 0,1, };

uint64_t Fibo(int InputNum)
{
	if (InputNum == 0 || InputNum == 1)
	{
		return Fibonum[InputNum];
	}		
	else if(Fibonum[InputNum])
	{
		return Fibonum[InputNum];
		//return Fibonum[InputNum];
	}
	else
	{
		return Fibonum[InputNum] = Fibo(InputNum - 1) + Fibo(InputNum - 2);
	}
}

int main()
{
	unsigned long start;
	start = clock();
	int InputNum = 0;
	cin >> InputNum;
	cout << (Fibo(InputNum))%10009 << endl;
	cout << clock() - start << endl;
	return 0;
}
