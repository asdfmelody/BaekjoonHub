#include <iostream>
using namespace std;
int N, M;
int arr[501][501];
int used[501][501];
int cnt;
int widthBest;
int width;

// 오 왼 위 아래
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void dfs(int y, int x)
{
	width++;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (used[ny][nx] == 1 || arr[ny][nx] == 0) continue;
		used[ny][nx] = 1;
		dfs(ny, nx);
	}
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> arr[y][x];
		}
	}
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (used[y][x] == 1 || arr[y][x] == 0) continue;
			used[y][x] = 1;
			width = 0;
			dfs(y, x);
			if (width > widthBest) widthBest = width;
			cnt++;
		}
	}
	cout << cnt << "\n" << widthBest;
}
