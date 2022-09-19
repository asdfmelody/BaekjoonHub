#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long an[100001];
long long am[100001];

void bs(long long in) {
	long long left = 0;
	long long right = n-1;
	while (left <= right) {
		long long mid = (long long)(left + right)/2;
		if (in == an[mid]) {
			cout << 1;
			cout << '\n';
			return;
		}
		else if (in < an[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << 0;
	cout << '\n';
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> an[i];
	}
	sort(an, an + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> am[i];
	}
	for (int i = 0; i < m; i++) {
		bs(am[i]);
	}
	return 0;
}