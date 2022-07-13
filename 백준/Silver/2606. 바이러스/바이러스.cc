#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int cnt = 0;
int arr[101][101];
bool used[101] = { 0, };
queue<int> q;

void bfs(int v) {
	q.push(v);
	used[v] = true;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (auto i = 1; i <= n; i++) {
			if (arr[v][i] == 1 && used[i] == 0) {
				q.push(i);
				used[i] = true;
				cnt++;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (auto i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	bfs(1);

	cout << cnt;
}