#include <iostream>
using namespace std;

bool sosu(int x) {
	if (x < 2) return false;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (sosu(input)) cnt++;
	}
	cout << cnt;
}