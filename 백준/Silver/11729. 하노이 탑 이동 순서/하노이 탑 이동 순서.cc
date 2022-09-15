#include <iostream>
#include <cmath>
using namespace std;

int N;

void rec(int n, int now, int blank, int next)
{
	if (n == 0) return;
	rec(n-1,now, next, blank);
	cout << now << " " << next<<"\n";
	rec(n - 1, blank, now, next);
}

int main()
{
	cin >> N;
	cout << (unsigned int)pow(2, N) - 1<<"\n";
	rec(N, 1, 2, 3);
	return 0;
}