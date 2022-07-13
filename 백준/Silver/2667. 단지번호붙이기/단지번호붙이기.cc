#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[26][26];
vector<int> result;
int used[26][26] = {0};
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ret = 0;
int cnt = 0;
int n;

void dfs(int y, int x) {
	used[y][x] = 1;
	map[y][x] = 2;
	ret++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;

		if (map[ny][nx] == 1 && used[ny][nx] == 0) {
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j]-'0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && used[i][j] == 0) {
				dfs(i, j);
				result.push_back(ret);
				ret = 0;
			}
		}
	}

	cout << result.size()<<"\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}