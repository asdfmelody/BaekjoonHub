#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}
	cin >> M;
	
	sort(arr.begin(), arr.end());

	int left = 0;
	int right = arr[N - 1];
	int result, sum;

	while (left <= right)
	{
		sum = 0;
		int mid = (left + right) / 2;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] <= mid) sum += arr[i];
			else sum += mid;
		}
		if (M >= sum)
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << result;
}