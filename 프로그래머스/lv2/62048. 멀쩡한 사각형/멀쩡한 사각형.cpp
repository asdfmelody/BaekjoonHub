#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w, int h) {
    long long answer = -1;
    //초ㅣ대공약수 구하기
    int ret = gcd(w,h);
    int W = w/ ret;
    int H = h/ ret;
    long long erase = ret * (W + H - 1);
    answer = ((long long)w*(long long)h) - erase;
    return answer;
}