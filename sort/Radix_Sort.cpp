#include <iostream>
#include <queue>
#include <vector>

#define MAX_BUCKET 10
using namespace std;

void Radix_Sort(int *arr, int size, int max)
{
	queue<int> buckets[MAX_BUCKET];
	int length, arrindex, radix, div = 1;

	for (length = 0; length < max; length++)
	{
		for (arrindex = 0; arrindex < size; arrindex++)
		{
			radix = (arr[arrindex] / div) % 10;
			buckets[radix].push(arr[arrindex]);
		}

		for (int qindex = 0, arrindex = 0; qindex < MAX_BUCKET; qindex++)
		{
			while (!buckets[qindex].empty())
			{
				arr[arrindex++] = buckets[qindex].front();
				buckets[qindex].pop();
			}
		}

		div *= 10;
	}
}

int main()
{
	int arr[7] = { 13,212,14,7141,10987,6,15 };
	int len = sizeof(arr) / sizeof(int);
	int max = 5;
	Radix_Sort(arr, len, max);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}