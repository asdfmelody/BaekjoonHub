#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 0;

	while (1) {
		a = floor(float((float)a / 2) + 0.5);
		b = floor(float((float)b / 2) + 0.5);
		answer++;
		if (a == b) break;
	}

	return answer;
}