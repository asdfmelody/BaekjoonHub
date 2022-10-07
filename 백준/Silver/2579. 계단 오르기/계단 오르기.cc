#include <iostream>
#include <queue>
using namespace std;

int n, ret;
int stairs[301];
int dp[301];

void run() {
	dp[0] = stairs[0];
	dp[1] = stairs[1] + stairs[0];
	dp[2] = max(stairs[0] + stairs[2],stairs[1]+stairs[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
}
int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}
	run();
	cout << dp[n - 1];
	return 0;
}