#include <iostream>
using namespace std;

int n;
int table[20][20];
int team1[10], team2[10];
int pick[20];
int ret;

void update() {
	int ts1 = 0, ts2 = 0;
	for (int i = 0; i < n; i++) {
		if (pick[i] == 0) {
			team1[ts1++] = i;
		}
		else {
			team2[ts2++] = i;
		}
	}
	
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = i+1; j < n / 2; j++) {
			sum1 += (table[team1[i]][team1[j]] + table[team1[j]][team1[i]]);
			sum2 += (table[team2[i]][team2[j]] + table[team2[j]][team2[i]]);
		}
	}
	if (ret > abs(sum1 - sum2)) {
		ret = abs(sum1 - sum2);
	}
}

void dfs(int now, int count) {
	if (count == (n / 2)) {
		update();
		return;
	}
	for (int i = now; i < n; i++) {
		pick[i] = 1;
		dfs(i + 1, count + 1);
		pick[i] = 0;
	}
}

int main() {

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> table[y][x];
		}
	}
	ret = 0x7fffffff;
	dfs(0, 0);
	cout << ret;
	return 0;
}