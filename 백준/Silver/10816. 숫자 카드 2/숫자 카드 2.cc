#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int an[20000001];
int m;
int am[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		an[input + 10000000]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> am[i];
	}
	for (int i = 0; i < m; i++) {
		cout << an[am[i]+10000000]<< " ";
	}

	return 0;
}