#include <iostream>
using namespace std;

void merge(int* arr, int *copyarr, int left, int mid, int right, int size)
{
	// l : 왼쪽 시작값,  m : 오른쪽 시작값,  index : 새로운 배열 인텍스값
	int l, m, index;
	l = left;
	m = mid + 1;
	index = left;

	//왼쪽값이과 오른쪽값 비교후 복사
	while (l <= mid && m <= right)
	{
		if (arr[l] <= arr[m])
		{
			copyarr[index++] = arr[l++];
		}
		else
		{
			copyarr[index++] = arr[m++];
		}
	}
	//왼쪽만 남을경우 복사
	if (l>mid)
	{
		for (int remainder = m; remainder <= right; remainder++)
		{
			copyarr[index++] = arr[remainder];
		}
	}
	// 오른쪽남을경우 복사
	else
	{
		for (int remainder = l; remainder <= mid; remainder++)
		{
			copyarr[index++] = arr[remainder];
		}
	}
	// 전체배열 재복사
	for (int a = left; a <= right; a++)
	{
		arr[a] = copyarr[a];
	}

}

void merge_sort(int *arr, int *copyarr, int left, int right, int size)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(arr, copyarr, left, mid, size);
		merge_sort(arr, copyarr, mid + 1, right, size);
		merge(arr, copyarr, left, mid, right, size);
	}
}

int main()
{
	int N;
	cin >> N;

	//동적할당후 초기화
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//새로운 배열
	int *copyarr = new int[N];

	//정열할 배열, 시작 인덱스, 마지막인덱스
	merge_sort(arr, copyarr, 0, N-1, N);

	//출력
	for (int j = 0; j < N; j++)
	{
		cout << arr[j] << " ";
	}
	
	//동적할당해제
	delete[] arr;
	//새로운 배열 해제
	delete[] copyarr;

	return 0;
}