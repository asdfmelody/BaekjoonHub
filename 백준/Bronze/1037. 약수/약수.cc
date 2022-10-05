#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int arr[51];

int main() {
	cin >> n;
	int res = 1;
	if (n == 1) {
		int a;
		cin >> a;
		res = a * a;
	}
	else {
		int mini = 1000000;
		int maxi = -1;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (mini > a) mini = a;
			if (maxi < a) maxi = a;
		}
		res = mini * maxi;
	}
	cout << res;
}