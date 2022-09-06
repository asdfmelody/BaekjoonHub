#include <iostream>
using namespace std;

int w, h;
int map[50][50];
int used[50][50];
int dy[8] = {1,1,1,0,0,-1,-1,-1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int y, int x)
{
	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if (map[ny][nx] && !used[ny][nx])
		{
			used[ny][nx] = 1;
			dfs(ny, nx);
		}
	}
}

int main()
{
	while (1)
	{
		int cnt = 0;

		//input
		cin >> w >> h;
		if (!w && !h) break;

		//input
		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cin >> map[y][x];
				used[y][x] = 0; // init;
			}
		}


		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				if (map[y][x] && !used[y][x])
				{
					used[y][x] = 1;
					dfs(y, x);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";

	}
	
}