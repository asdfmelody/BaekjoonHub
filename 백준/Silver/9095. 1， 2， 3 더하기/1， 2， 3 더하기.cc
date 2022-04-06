#include<iostream>

using namespace std;

int dp[11];
int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int l = 4; l <= k; l++) {
			dp[l] = dp[l - 3] + dp[l - 2] + dp[l - 1];
		}
		cout << dp[k]<<endl;

	}

	return 0;
}