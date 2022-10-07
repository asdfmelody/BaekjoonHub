#include <iostream>
using namespace std;

int n;
int arr[100001];
int cha[100000];
int mini = 1000000000;
int maxi = -1;
int yak;
int ret;

bool check(int k) {
	for (int i = 0; i < n - 1; i++) {
		if (cha[i] % k != 0) return false;
	}
	return true;
}

void run() {
	//cha 중 가장 작은수 구하기
	int mincha = 1000000000;
	for (int i = 0; i < n - 1; i++) {
		if (mincha > cha[i]) mincha = cha[i];
	}

	for (int k = mincha; k > 0; k--) {
		if (check(k)) {
			yak = k;
			return;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr[i] = input;
		if (mini > input) mini = input;
		if (maxi < input) maxi = input;
	}
	//차이 구하기
	for (int i = 1; i < n; i++) {
		cha[i - 1] = arr[i] - arr[i - 1];
	}
	// 최대공약수 구하기
	run();

	ret = ((maxi - mini) / yak) - n + 1;
	
	cout << ret;

	return 0;
}