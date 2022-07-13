#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int maze[101][101] = { 0 };
int used[101][101] = { 0 };
int dist[101][101] = { 0 };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

queue<pair<int, int>> q;

int main() {
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			maze[i][j] = str[j] - '0';
		}
	}

	//bfs
	used[0][0] = 1;	
	dist[0][0]++;

	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !used[nx][ny] && maze[nx][ny] == 1) {
				used[nx][ny] = true;
				q.push({ nx, ny });
				dist[nx][ny] = dist[tx][ty] + 1;
			}
		}
	}

	cout << dist[N - 1][M - 1];

	return 0;
}