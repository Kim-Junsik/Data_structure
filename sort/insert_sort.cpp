#include <iostream>
using namespace std;

void insert_sort(int *arr, int size)
{
	int temp;
	size_t i, j;
	for (i = 1; i < size; ++i)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (temp < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j+1] = temp;
	}
}

int main()
{
	int arr[] = { 5,3,2,4,1 };
	int size = sizeof(arr) / sizeof(int);
	insert_sort(arr, size);
	for (size_t i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	return 0;
}