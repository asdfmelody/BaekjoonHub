#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Arr;
vector<int> Answer;

void flag(int starty, int startx, int size) {
	int zeroF=0; // 하나라도 1나오면 zeroF 1
	int oneF=0;
	for (int y = starty; y < starty+size; y++) {
		for (int x = startx; x < startx+size; x++) {
			if (Arr[y][x] == 1) zeroF = 1;
			if (Arr[y][x] == 0) oneF = 1;
			if (zeroF == 1 and oneF == 1) goto A;
		}
	}
	if (zeroF == 0 and oneF == 0) return;
	if (zeroF == 0) {
		Answer[0] ++;
		return;
	}
	else if (oneF == 0) {
		Answer[1]++;
		return; 
	}
	A:
	flag(starty, startx, size / 2);
	flag(starty, startx + size / 2, size / 2);
	flag(starty + size / 2, startx, size / 2);
	flag(starty + size / 2, startx + size / 2, size / 2);
}

vector<int> solution(vector<vector<int>> arr) {
	Arr = arr;
	vector<int> answer(2,0);
	Answer = answer;

	flag(0,0,arr.size());

	return Answer;
}