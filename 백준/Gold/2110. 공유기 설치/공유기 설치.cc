#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> arr;
int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	int left = 0;
	int right = arr[N - 1];
	int result = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int temp = 0, count = 1;
		for (int i = 1; i < N; i++)
		{
			if (arr[i] - arr[temp] >= mid) //거리 구하기
			{
				temp = i;
				count++;
			}
		}
		if (count >= C) //공유기 개수가 많으면
		{
			result = mid;
			left = mid + 1; //거리를 더 늘려도 됨.
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << result;
}