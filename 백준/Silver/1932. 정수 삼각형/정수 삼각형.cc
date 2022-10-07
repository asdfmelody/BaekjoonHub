#include <iostream>
using namespace std;

int triangle[501][501];
int dp[501][501];
int n, ret;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> triangle[i][j];
		}
	}
	dp[0][0] = triangle[0][0];
	dp[1][0] = dp[0][0] + triangle[1][0];
	dp[1][1] = dp[0][0] + triangle[1][1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][0] + triangle[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			ret = max(ret, dp[i][j]);
		}
	}
	cout << ret;
	return 0;
}