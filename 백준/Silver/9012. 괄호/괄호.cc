#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void check(string str) {
	int len = str.size();
	int open = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(')open++;
		else open--;
		if (open < 0) {
			cout << "NO";
			return;
		}
	}
	if (open == 0) cout << "YES";
	else cout << "NO";
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		check(input);
		cout << "\n";
	}

	return 0;
}