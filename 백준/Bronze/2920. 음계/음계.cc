#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int arr[8];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int flag = 0;
	//ascending
	for (int i = 1; i < 8; i++) {
		if (arr[i - 1] < arr[i]) continue;
		else {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "ascending";
		return 0;
	}

	//descending
	for (int i = 1; i < 8; i++) {
		if (arr[i - 1] > arr[i]) continue;
		else {
			flag = 2;
			break;
		}
	}
	if (flag == 1) {
		cout << "descending";
		return 0;
	}

	cout << "mixed";
	return 0;
	
}