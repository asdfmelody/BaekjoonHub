// 에라토스테네스의 체
// https://asdfmelody.tistory.com/71?category=864129
#include <iostream>
#include <math.h>
using namespace std;

int M, N;

int arr[1000001];

void run()
{
	for (int i = 2; i <= N; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= N; j += i)
		{
			arr[j] = 0;
		}
	}
}

int main()
{
	cin >> M >> N;
	run();
	for (int i = M; i <= N; i++)
	{
		if (arr[i] == 0)continue;
		cout << i << "\n";
	}
}
