#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, k;
int a, b, c, d;

int map[101][101];

int cnt = 0;
int sizes[5001];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

struct node {
	int y, x;
};

void box(int a, int b, int c, int d) {
	for (int x = a; x < c; x++) {
		for (int y = b; y < d; y++) {
			map[y][x] = 1;
		}
	}
}

void bfs(int y, int x) {
	queue<node> q;
	q.push({ y, x });
	map[y][x] = 2;

	int sz = 1;

	while (!q.empty()) {
		node front = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nexty = front.y + dy[i];
			int nextx = front.x + dx[i];

			if (nexty < 0 || nextx < 0 || nexty >= m || nextx >= n) continue;
			
			if (map[nexty][nextx] == 0) {
				q.push({ nexty, nextx });
				map[nexty][nextx] = 2;
				sz++;
			}
		}
	}
	sizes[cnt] = sz;
}

int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c >> d;
		box(a, b, c, d);
	}

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 0) {
				bfs(y, x);
				cnt++;
			}
		}
	}
	cout << cnt<< "\n";

	//오름차순 정렬
	sort(sizes, sizes + cnt);

	for (int i = 0; i < cnt; i++) cout << sizes[i] << " ";

	return 0;
}