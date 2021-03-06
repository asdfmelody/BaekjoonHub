#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000000];

int main() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	int n;
	cin >> n;

	for (int i = 4; i <= n; i++) {
		int m = dp[i - 1] + 1;
		if ((i % 2) == 0) m = min(m, dp[i / 2] + 1);
		if ((i % 3) == 0) m = min(m, dp[i / 3] + 1);
		dp[i] = m;
	}
	cout << dp[n];

	return 0;
}