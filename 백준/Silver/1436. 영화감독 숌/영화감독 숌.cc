#include <iostream>
#include <string>
using namespace std;

int n;
int ret = 666;

int main()
{
	cin >> n;
	int now = 0;
	while (1)
	{
		string str = to_string(ret);
		if (str.find("666") != str.npos)
		{
			now++;
			if (now == n)
			{
				cout << ret;
				break;
			}
		}
		ret++;
	}
}