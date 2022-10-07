#include <iostream>
using namespace std;

bool sosu[1000001];
int tc[100001];
int l, r;

bool validate(int x) {
	for (int i = 3; i < x; i++) {
		if (sosu[i] == 0 && sosu[x - i] == 0) {
			l = i, r = x - i;
			return true;
		}
	}
	return false;
}

void print(int x) {
	// 검증과 출력
	if (validate(x)) {
		cout << x << " = " << l << " + " << r;
	}
	else {
		cout << "Goldbach's conjecture is wrong.";
	}
	cout << "\n";
}

int main() {

	// 입력
	int cs = 0;
	while (1) {
		int input;
		cin >> input;
		if (input == 0) break;
		tc[cs++] = input;
	}

	// 소수 찾기
	for (int i = 2; i < 1000; i++) {
		if (sosu[i] == 1) continue;
		int basu = 2;
		while (1) {
			if (i * basu > 1000000) break;
			sosu[i * basu] = 1;
			basu++;
		}
	}
	sosu[2] = 1;

	for (int i = 0; i < cs; i++) {
		print(tc[i]);
	}

	return 0;
}