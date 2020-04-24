#include <iostream>
using namespace std;

void bubble_sort(int *arr, int size)
{
	for (int i = 0; i < size-1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = { 3,2,4,1 };
	unsigned int i;
	int size = sizeof(arr) / sizeof(int);
	bubble_sort(arr, size);
	for (i = 0; i < size; ++i)
		cout << arr[i] << ' ';

	return 0;
}
