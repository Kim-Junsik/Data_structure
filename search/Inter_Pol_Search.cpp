#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int b_search(vector<int>& arr, int start, int size, int data)
{
	int last = size - 1;
	if (arr[start] > data || arr[last] < data)
		return -1;

	int mid = ((double)(data - arr[start])/(arr[last]-arr[start])*(last -start)) + start;

	if (arr[mid] == data)
		return arr[mid];
	else if (arr[mid] > data)
		return b_search(arr, start, mid - 1, data);
	else if (arr[mid]<data)
		return b_search(arr, mid + 1, last, data);
}

int main()
{
	vector<int> arr{ 9,8,3,2,6,5,7,4,1,10 };
	sort(begin(arr), end(arr), less<>());
	int s_data = 8;
	int search = b_search(arr, 0, arr.size(), s_data);

	if (search == -1 || search != s_data)
		cout << "데이터를 찾지 못했습니다." << endl;
	else
		cout << "데이터를 찾았습니다." << endl;
	return 0;
}