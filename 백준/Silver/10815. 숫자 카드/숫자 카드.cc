#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int an[500001];
int am[500001];

void bs(int in) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (an[mid] == in) {
			cout << 1;
			return;
		}
		else if (an[mid] > in) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << 0;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> an[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> am[i];
	}

	sort(an, an + n);

	for (int i = 0; i < m; i++) {
		bs(am[i]);
		cout << ' ';
	}

	
	return 0;
}