#include <iostream>
#include <vector>
#include <string>
using namespace std;

string answer="";
bool used[100002];
bool isNo = false;
int n;

bool cha(int bef, int now)
{
	for (int i = bef+1; i < now; i++)
	{
		if (used[i] == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n;
	int bef = 1;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		int now;
		cin >> now;
		if (now == n)
		{
			for (int k = bef; k <= now; k++)
			{
				if (!used[k]) answer += "+\n";
			}
			answer += "-\n";
			used[now] = 1;
			bef = now;
			flag = 1;
			continue;
		}
		if (flag == 0)
		{
			if (bef <= now)
			{
				for (int k = bef; k <= now; k++)
				{
					if (!used[k]) answer += "+\n";
				}
				used[now] = 1;
				answer += "-\n";
				bef = now;
				continue;
			}
			else if (bef > now)
			{
				if (bef - now == 1 || cha(bef,now))
				{
					bef = now;
					if (!used[now]) answer += "-\n";
					used[now] = 1;
					continue;
				}
				else
				{
					isNo = true;
					break;
				}
			}
		}
		else
		{
			if (now < bef)
			{
				for (int k = now; k < bef; k++)
				{
					if (!used[k]) answer += "-\n";
				}
				used[now] = 1;
				bef = now;
			}
			else
			{
				isNo = true;
				break;
			}
		}
	}
	if (isNo) cout << "NO";
	else if (answer.size() > 4 * n) cout << "NO";
	else cout << answer;
	return 0;
}