#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <int> v[1001];
int dfs_used[1001];

queue<int> q;
int bfs_used[1001];

void dfs(int now) {
	cout << now << " ";
	dfs_used[now] = 1;

	sort(v[now].begin(), v[now].end());
	for (int i = 0; i < v[now].size(); i++) {
		int to = v[now][i];
		if (dfs_used[to] == 1) continue;
		dfs(to);
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	dfs(V);
	cout << "\n";

	q.push(V);
	//bfs(V);
	bfs_used[V] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " "; //왜 안됨? ㅡㅡ

		sort(v[now].begin(), v[now].end());
		for (int i = 0; i < v[now].size(); i++) {
			int to = v[now][i];
			if (bfs_used[to] != 0) continue;
			if (to == 0) continue;
			bfs_used[to] = 1;
			q.push(to);
		}
	}
	return 0;
}