#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int arr[101][101];
int dat[101][101];

int input;
int mx = -1;
int mn = 101;

int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};

void init()
{
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			dat[i][j] = 0;
		}
	}
}

void rain(int k)
{
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (arr[i][j] > k) dat[i][j] = 1; // 안잠긴 곳 1
		}
	}
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;

	q.push(make_pair(y, x));

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (dat[ny][nx] == 1)
			{
				dat[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			int in;
			cin >> in;
			arr[i][j] = in;
			if (in > mx) mx = in;
			if (in < mn) mn = in;
		}
	}

	int answer = 0;

	for (int i = mn; i <= mx; i++)
	{
		init();
		rain(i);

		int ret = 0;
		for (int i = 0; i < input; i++)
		{
			for (int j = 0; j < input; j++)
			{
				if (dat[i][j] == 1)
				{
					bfs(i, j);
					ret++;
				}
			}
		}
		if (ret > answer) answer = ret;
	}

	if (answer == 0) answer = 1;
	cout << answer;

	return 0;

}