#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int left = 0;
	int right = N - 1;
	int ans = 0;

	while (left < right) {
		if (arr[left] + arr[right] >= M) {
			ans++;
			left++;
			right--;
		}
		else {
			left++;
		}
	}

	cout << ans;
	return 0;
}