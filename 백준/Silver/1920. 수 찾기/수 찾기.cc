#include <iostream>
#include <algorithm>
using namespace std;

int N;
int an[100001];
int M;
int am[100001];

void bs(int n)
{
	// an에서 n찾기
	// start mid end 는 index 기반
	int start = 0;
	int end = N - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int now = an[mid];
		if (now == n)
		{
			cout << 1;
			return;
		}
		else if (now > n)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << 0;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> an[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> am[i];
	}

	//an 정렬
	sort(an, an + N);
	for (int i = 0; i < M; i++)
	{
		bs(am[i]);
		cout << "\n";
	}
}
	
