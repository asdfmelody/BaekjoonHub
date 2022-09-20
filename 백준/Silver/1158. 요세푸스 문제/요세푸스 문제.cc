#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	cout << "<";
	while (q.size() > 1) {
		for (int i = 0; i < k - 1; i++) {
			int temp = q.front();
			q.push(temp);
			q.pop();
		}
		cout << q.front()<<", ";
		q.pop();
	}
	cout << q.front();
	cout << ">";
	return 0;
}