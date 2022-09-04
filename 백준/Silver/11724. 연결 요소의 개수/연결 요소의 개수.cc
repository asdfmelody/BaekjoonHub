#include <iostream>
using namespace std;

int N, M;

int arr[1001][1001];
int visited[1001];
int cnt;

void dfs(int now)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[now][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int m = 0; m < M; m++)
	{
		int u, v;
		cin >> u >> v;
		arr[u-1][v-1] = 1;
		arr[v-1][u-1] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}