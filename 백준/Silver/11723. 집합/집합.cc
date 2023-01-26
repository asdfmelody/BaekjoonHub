#include <iostream>
#include <string>
using namespace std;

int tc;

int S = 0;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "add") {
			int x;
			cin >> x;
			S = S | (1 << x);
		}
		else if (str == "remove") {
			int x;
			cin >> x;
			S = S & ~(1 << x);
		}
		else if (str == "check") {
			int x;
			cin >> x;
			if (S & (1 << x)) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "toggle") {
			int x;
			cin >> x;
			if (S & (1 << x)) {
				S = S & ~(1 << x);
			}
			else {
				S = S | (1 << x);
			}
		}
		else if (str == "all") {
			S = (1 << 21) - 1;
		}
		else {
			S = 0;
		}
	}

	return 0;
}