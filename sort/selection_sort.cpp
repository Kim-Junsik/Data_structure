#include <iostream>
using namespace std;

void selection_sort(int *arr, int size)
{
	int maxindex, temp = 0;
	for (size_t i = 0; i < size -1; ++i)
	{
		maxindex = i;
		for (size_t j = i+1; j < size; ++j)
		{
			if (arr[maxindex] > arr[j])
			{
				maxindex = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[maxindex];
		arr[maxindex] = temp;
	}
}

int main()
{
	int arr[10] = { 7,6,10,9,1,3,2,8,4,5 };
	int size = sizeof(arr)/ sizeof(int);
	selection_sort(arr, size);

	for (size_t i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	return 0;
}