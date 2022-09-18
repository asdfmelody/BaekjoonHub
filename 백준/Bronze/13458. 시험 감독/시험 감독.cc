#include <iostream>
#include <string>
using namespace std;
int N, B, C;
int arr[1000001];
long long answer;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> B >> C;

	// 총 감독관 배치
	answer = N;
	for (int i = 0; i < N; i++)
	{
		arr[i] -= B;
	}

	// 부 감독관 배치
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > 0)
		{
			int mok = arr[i] / C;
			answer += mok;
			if ((arr[i] % C) != 0) answer += 1;
		}
	}
	cout << answer;
	return 0;
}