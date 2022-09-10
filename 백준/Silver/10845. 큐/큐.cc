#include <iostream>
#include <string>
using namespace std;

int N;
int arr[10001];
int start;
int nd;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int x;
			cin >> x;
			arr[nd] = x;
			nd++;
		}
		else if (str == "pop")
		{
			if (nd == start)
			{
				cout << -1 << "\n";
				continue;
			}
			cout << arr[start] << "\n";
			start++;
		}
		else if (str == "size")
		{
			cout << nd - start;
			cout << "\n";
		}
		else if (str == "empty")
		{
			nd - start ? cout << 0 : cout << 1;
			cout << "\n";
		}
		else if (str == "front")
		{
			if (nd == start)
			{
				cout << -1 << "\n";
				continue;
			}
			cout << arr[start] << "\n";
		}
		else if (str == "back")
		{
			if (nd == start)
			{
				cout << -1 << "\n";
				continue;
			}
			cout << arr[nd-1] << "\n";
		}
	}
}
	
