#include <iostream>
#include <string>
using namespace std;

int N;
int arr[10001];
int now;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int x;
			cin >> x;
			arr[now] = x;
			now++;
		}
		else if (input == "pop")
		{
			if (now == 0)
			{
				cout << -1 << "\n";
				continue;
			}
			now--;
			cout << arr[now];
			cout << "\n";
		}
		else if (input == "size")
		{
			cout << now;
			cout << "\n";
		}
		else if (input == "empty")
		{
			now == 0 ? cout << 1 : cout << 0;
			cout << "\n";
		}
		else if (input == "top")
		{
			if (now == 0)
			{
				cout << -1 << "\n";
				continue;
			}
			cout << arr[now - 1];
			cout << "\n";
		}
	}
}
