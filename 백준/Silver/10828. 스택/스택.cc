#include <iostream>
using namespace std;

int n;
int stack[10001];
int now;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		string action;
		cin >> action;
		if (action == "push") {
			int k;
			cin >> k;
			stack[now] = k;
			now++;
		}
		else if (action == "pop") {
			if (now == 0) cout << -1;
			else {
				cout << stack[now-1];
				now--;
			}
			cout << '\n';
		}
		else if (action == "size") {
			cout << now;
			cout << '\n';
		}
		else if (action == "empty") {
			if (now) cout << 0;
			else cout << 1;
			cout << '\n';
		}
		else if (action == "top") {
			if (now == 0)cout << -1;
			else cout << stack[now-1];
			cout << '\n';
		}
	}
	
	return 0;
}