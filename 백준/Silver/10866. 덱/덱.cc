#include <iostream>
using namespace std;

int n;
int stack[30000];
int front=15000;
int back=15000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		string action;
		cin >> action;
		if (action == "push_front") {
			int x;
			cin >> x;
			stack[front-1] = x;
			front--;
		}
		else if (action == "push_back") {
			int x;
			cin >> x;
			stack[back] = x;
			back++;
		}
		else if (action == "pop_front") {
			if (back == front) cout << -1;
			else {
				cout << stack[front];
				front++;
			}
			cout << '\n';
		}
		else if (action == "pop_back") {
			if (back == front) cout << -1;
			else {
				cout << stack[back-1];
				back--;
			}
			cout << '\n';
		}
		else if (action == "size") {
			cout << back-front;
			cout << '\n';
		}
		else if (action == "empty") {
			if (back == front) cout << 1;
			else cout << 0;
			cout << '\n';
		}
		else if (action == "front") {
			if (back == front) cout << -1;
			else cout << stack[front];
			cout << '\n';
		}
		else if (action == "back") {
			if (back == front) cout << -1;
			else cout << stack[back-1];
			cout << '\n';
		}
	}
	
	return 0;
}