#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	vector<int> lan;
	long long right = -1;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		lan.push_back(tmp);
		if (right < tmp) right = tmp;
	}

	long long left = 1;
	int mx = 0;
	while (left <= right) {
		long long mid = (left+right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += lan[i] / mid;
		}
		if (cnt >= n) {
			left = mid + 1;
			if (mx < mid) mx = mid;
		}
		else {
			right = mid - 1;
		}
	}

	cout << mx;

}