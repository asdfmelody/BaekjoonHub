#include <iostream>
using namespace std;

int n;
int stack[10001];
int front;
int back;

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
			int x;
			cin >> x;
			stack[back] = x;
			back++;
		}
		else if (action == "pop") {
			if (front == back) cout << -1;
			else {
				cout << stack[front];
				front++;
			}
			cout << '\n';
		}
		else if (action == "size") {
			cout << back - front;
			cout << '\n';
		}
		else if (action == "empty") {
			if (front == back) cout << 1;
			else cout << 0;
			cout << '\n';
		}
		else if (action == "front") {
			if (front == back) cout << -1;
			else cout << stack[front];
			cout << '\n';
		}
		else if (action == "back") {
			if (front == back) cout << -1;
			else cout << stack[back-1];
			cout << '\n';
		}
	}
	
	return 0;
}