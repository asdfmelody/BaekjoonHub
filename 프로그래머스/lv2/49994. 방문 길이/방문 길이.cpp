#include <string>
using namespace std;

int ud[11][11];
int rl[11][11];

int solution(string dirs) {
	int answer = 0;
	int y = 5;
	int x = 5;
	for (int i = 0; i < dirs.size(); i++) {
		char now = dirs[i];
		if (now == 'U') {
			if (y <= 0) continue;
			y--;
			if (ud[y][x] == 1) continue;
			answer++;
			ud[y][x] = 1;
		}
		else if (now == 'D') {
			if (y >= 10) continue;
			y++;
			if (ud[y-1][x] == 1) continue;
			answer++;
			ud[y-1][x] = 1;
		}
		else if (now == 'R') {
			if (x >= 10) continue;
			x++;
			if (rl[y][x-1] == 1) continue;
			answer++;
			rl[y][x - 1] = 1;
		}
		else if (now == 'L') {
			if (x <= 0) continue;
			x--;
			if (rl[y][x] == 1) continue;
			answer++;
			rl[y][x] = 1;
		}
	}
	return answer;
}