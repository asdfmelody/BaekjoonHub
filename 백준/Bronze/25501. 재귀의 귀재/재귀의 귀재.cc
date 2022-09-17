#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

int cnt;

int recursion(const char *s, int l, int r)
{
	cnt+=1;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s)
{
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		char a[1001];
		cnt = 0;
		cin >> a;
		cout << isPalindrome(a);
		cout << " ";
		cout << cnt;
		cout << "\n";
	}
}