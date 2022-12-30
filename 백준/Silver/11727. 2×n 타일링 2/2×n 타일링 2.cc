#include <iostream>
using namespace std;

int dp[1001];

int main() {
	int n;
	cin >> n;

	dp[1] = 1;

	//짝수면 + 홀수면 -
	for (int i = 2; i <= n; i++) {
		int d = 1;
		if (i % 2 == 1) d = -1;
		dp[i] = ((dp[i - 1] * 2) + d) % 10007;
	}
	
	//10007로 나눈 나머지 값 출력
	cout << dp[n];

	return 0;
}