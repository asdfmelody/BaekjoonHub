#include <iostream>

using namespace std;

int answer = -1;

void rec(long long a, long long b, long long n) {

	if (a > b) return;

	if (a == b) {
		if (answer == -1) answer = n;
		else if (answer > n ) answer = n;
		return;
	}

	rec(a * 2, b,n+1);
	rec((a*10) + 1, b,n+1);

}

int main() {
	long long a, b;
	cin >> a >> b;

	rec(a, b, 1);
	
	cout << answer;

	return 0;
}