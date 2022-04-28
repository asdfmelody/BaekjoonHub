#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int y;
	int answer = 0;
	cin >> y;
	if (y % 4 == 0 && y % 100 != 0) answer = 1;
	else if(y % 4 == 0 && y % 400 == 0) answer = 1;

	cout << answer;
	return 0;
}