#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int T;
int N;
int M;
struct Node
{
	int index, importance;
};
int arr[101];

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		queue<Node> que;
		for (int n = 0; n < N; n++)
		{
			int imp;
			cin >> imp;
			que.push({n, imp});
			arr[n] = imp;
		}
		sort(arr, arr + N,greater<int>());
		int flag = 0;
		int l = 0;
		while (!que.empty())
		{
			Node now = que.front();
			que.pop();
			if (arr[l] == now.importance)
			{
				l++;
				if (now.index == M)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				que.push(now);
			}
		}
		cout << l << "\n";
	}
	return 0;
}