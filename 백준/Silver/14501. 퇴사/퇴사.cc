#include <iostream>
using namespace std;

int n;
int t[16];
int p[16];
int dp[16];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    int deadline;
    for (int i = n; i > 0; i--) {
        deadline = i + t[i];
        if (deadline > n + 1) dp[i] = dp[i + 1];
        else dp[i] = max(dp[i + 1], dp[deadline] + p[i]);
    }

    cout << dp[1];
    return 0;
}