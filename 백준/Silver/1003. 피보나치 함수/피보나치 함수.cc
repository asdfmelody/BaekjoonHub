#include <iostream>
using namespace std;

int t;

struct table {
	int zero = 0;
	int one = 0;
};
table fib[41];

int main() {

	fib[0].zero = 1;
	fib[1].one = 1;
	for (int i = 2; i < 41; i++) {
		fib[i].zero = fib[i - 1].zero + fib[i - 2].zero;
		fib[i].one = fib[i - 1].one + fib[i - 2].one;
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		int input;
		cin >> input;
		cout << fib[input].zero << " " << fib[input].one << "\n";
	}
	return 0;
}