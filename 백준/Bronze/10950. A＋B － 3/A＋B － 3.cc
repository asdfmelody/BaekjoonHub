#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cout << x + y << "\n";
	}
	return 0;
}