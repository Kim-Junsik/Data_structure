#include <iostream>

using namespace std;

void Merge_Sort(int *arr, int left, int mid, int right, int size)
{
	int leftindex = left;
	int midindex = mid + 1;
	int newindex = left;
	int *newarr = new int[size];

	while (leftindex <= mid && midindex <= right)
	{
		if (arr[leftindex] < arr[midindex])
		{
			newarr[newindex++] = arr[leftindex++];
		}
		else
		{
			newarr[newindex++] = arr[midindex++];
		}
	}

	if (leftindex > mid)
	{
		for (size_t i = midindex; i <= right; ++i)
		{
			newarr[newindex++] = arr[i];
		}
	}
	else
	{
		for (size_t i = leftindex; i <= mid; ++i)
		{
			newarr[newindex++] = arr[i];
		}
	}

	for (size_t j = left; j <= right; ++j)
	{
		arr[j] = newarr[j];
	}

	delete[] newarr;
}

void Merge(int *arr, int left, int right, int size)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		Merge(arr, left, mid, size);
		Merge(arr, mid + 1, right, size);

		Merge_Sort(arr, left, mid, right, size);
	}
}

int main()
{
	int arr[] = { 3,2,4,1,7,6,5 };
	int size = sizeof(arr) / sizeof(int);

	Merge(arr, 0, size - 1, size);
	for (size_t i = 0; i < size; ++i)
	{
		cout << arr[i] << endl;
	}
	return 0;
}