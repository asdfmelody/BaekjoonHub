#include <iostream>
#include <string>
using namespace std;

string X;
int cnt;
bool ret;

void recursive(string now)
{
	int len = now.length();
	if (len == 1)
	{
		if (now == "3" || now == "6" || now == "9") ret = true;
		else ret = false;
		return;
	}
	cnt++;
	long long sum = 0;
	for (int i = 0; i < len; i++)
	{
		char a = now[i];
		int k = a - '0';
		sum += k;
	}
	return recursive(to_string(sum));
}

int main()
{
	cin >> X;
	recursive(X);
	cout << cnt << "\n";
	ret ? cout << "YES" : cout << "NO";

}