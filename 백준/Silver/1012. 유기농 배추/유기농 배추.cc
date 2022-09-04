#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int y, x;
};

int T;
int M, N, K;
int arr[50][50];
int visited[50][50];
int cnt = 0;

void init()
{
	cnt = 0;
	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			arr[y][x] = 0;
			visited[y][x] = 0;
		}
	}
}
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void dfs(int y,int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (nexty < 0 || nexty >= N || nextx < 0 || nextx >= M) continue;
		if (!arr[nexty][nextx]) continue;
		if (visited[nexty][nextx])continue;
		visited[nexty][nextx] = 1;
		dfs(nexty, nextx);
	}
}

int main()
{
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		init();
		cin >> M >> N >> K;
		for (int k = 0; k < K; k++)
		{
			int y, x;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (arr[y][x] && !visited[y][x])
				{
					cnt++;
					visited[y][x] = 1;
					dfs(y, x);
				}
			}
		}
		cout << cnt << "\n";
	}
}