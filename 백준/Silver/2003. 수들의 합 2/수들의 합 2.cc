#include <iostream>
using namespace std;

int N, M;
int arr[10001];
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 1;
	int ans = 0;
	while (right <= N) {
		int hap = 0;
		for (int i = left; i < right; i++) {
			hap += arr[i];
		}
		if (hap > M) left++;
		else if (hap < M) right++;
		else {
			ans++;
			left++; right++;
		}
	}
	cout << ans;
	return 0;
}