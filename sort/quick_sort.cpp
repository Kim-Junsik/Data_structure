#include <iostream>
#define SWAP(temp, x, y) ((temp) = (x), (x) = (y), (y) = (temp))
using namespace std;

int quick_sort(int *arr, int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int hight = right;
	int temp = 0;
	while (low <= hight)
	{
		while (pivot >= arr[low] && low<=right)
		{
			++low;
		}
		while (pivot <= arr[hight] && hight>=(left+1))
		{
			--hight;
		}

		if (low <= hight)
		{
			SWAP(temp, arr[low], arr[hight]);
		}	
	}

	SWAP(temp, arr[left], arr[hight]);

	return hight;
}

void quick(int *arr, int left, int right)
{
	if (left <= right)
	{
		int pivot = quick_sort(arr, left, right);
		quick(arr, left, pivot-1);
		quick(arr, pivot + 1, right);
	}
}

int main()
{
	int arr1[7] = { 3,2,4,1,7,6,5 };
	int arr2[3] = { 3,3,3 };

	int size1 = sizeof(arr1) / sizeof(int);
	int size2 = sizeof(arr2) / sizeof(int);

	quick(arr1, 0, size1-1);
	quick(arr2, 0, size2-1);

	for (size_t i = 0; i < size1; ++i)
	{
		cout << arr1[i] << ' ';
	}
	cout << endl;
	for (size_t j = 0; j < size2; ++j)
	{
		cout << arr2[j] << ' ';
	}
	cout << endl;

	return 0;
}
