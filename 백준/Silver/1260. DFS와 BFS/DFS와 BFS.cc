#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[1001][1001];

int N, M, sp; 
vector<int>dfsUsed;

void dfs(int n) {
	cout << n << " ";
	for (int i = 1; i <= N; i++) {
		if (dfsUsed[i] != 0) continue;
		if (arr[n][i] == 1) {
			arr[n][i] = 2;
			arr[i][n] = 2;
			dfsUsed[i] = 1;
			dfs(i);
		}
	}
}

void bfs(int n) {
	queue<int> q;
	vector<int> used(N+1, 0);
	q.push(n);
	used[n] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int to = 1; to <= N; to++) {
			if (used[to] != 0) continue;
			if (arr[now][to] == 0) continue;
			used[to] = 1;
			q.push(to);
		}
	}


}

void init() {
	for (int i = 0; i < M; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		arr[p1][p2] = 1;
		arr[p2][p1] = 1;
	}
}

int main() {
	cin >> N >> M >> sp;
	
	init();

	dfsUsed = vector<int>(N+1, 0);
	dfsUsed[sp] = 1;
	dfs(sp);
	cout << "\n";
	bfs(sp);

	return 0;
}