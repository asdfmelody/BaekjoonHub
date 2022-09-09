#include <iostream>
#include <string>
using namespace std;

int T;
string input;

bool run()
{
	int cnt = 0;
	for (char c : input)
	{
		if (c == '(') cnt++;
		else cnt--;
		if (cnt < 0) return false;
	}
	if (cnt == 0) return true;
	else return false;
}

int main()
{
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> input;
		run() ? cout << "YES\n" : cout << "NO\n";
	}
}
