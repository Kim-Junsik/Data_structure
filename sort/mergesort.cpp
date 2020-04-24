#include <iostream>
using namespace std;

void merge(int* arr, int *copyarr, int left, int mid, int right, int size)
{
	// l : ���� ���۰�,  m : ������ ���۰�,  index : ���ο� �迭 ���ؽ���
	int l, m, index;
	l = left;
	m = mid + 1;
	index = left;

	//���ʰ��̰� �����ʰ� ���� ����
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
	//���ʸ� ������� ����
	if (l>mid)
	{
		for (int remainder = m; remainder <= right; remainder++)
		{
			copyarr[index++] = arr[remainder];
		}
	}
	// �����ʳ������ ����
	else
	{
		for (int remainder = l; remainder <= mid; remainder++)
		{
			copyarr[index++] = arr[remainder];
		}
	}
	// ��ü�迭 �纹��
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

	//�����Ҵ��� �ʱ�ȭ
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//���ο� �迭
	int *copyarr = new int[N];

	//������ �迭, ���� �ε���, �������ε���
	merge_sort(arr, copyarr, 0, N-1, N);

	//���
	for (int j = 0; j < N; j++)
	{
		cout << arr[j] << " ";
	}
	
	//�����Ҵ�����
	delete[] arr;
	//���ο� �迭 ����
	delete[] copyarr;

	return 0;
}