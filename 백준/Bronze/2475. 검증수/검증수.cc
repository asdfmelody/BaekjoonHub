#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		sum += pow(x, 2);
	}
	int answer = sum % 10;
	cout << answer;
	return 0;
}