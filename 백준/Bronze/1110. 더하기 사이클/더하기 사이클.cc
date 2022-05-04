#include <iostream>

using namespace std;
int main() {
	int input;
	cin >> input;
	int cnt = 0;
	int temp = input;
	while (1) {
		temp = ((temp%10) * 10) + ((temp / 10 + temp % 10)%10);
		cnt++;
		if (input == temp) break;
	}
	cout << cnt;
	return 0;
}