#include <iostream>
using namespace std;

int n;
int arr[1001][3];//빨초파
int color[1001][3];

int main() {
	//input
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> arr[y][x];
		}
	}

	for (int i = 1; i < n; i++) {
		arr[i][0] += min(arr[i-1][1], arr[i - 1][2]);
		arr[i][1] += min(arr[i-1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i-1][0], arr[i - 1][1]);
	}

	cout << min(arr[n - 1][0], min(arr[n - 1][2], arr[n - 1][1]));

	return 0;
}