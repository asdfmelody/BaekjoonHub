#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101];
void makearr(int r, int c) {
	int i = 1;
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			arr[y][x] = i++;
		}
	}
}

int rotate(vector<int> q) { // 가장작은수 리턴 & 회전
	int x1, y1, x2, y2;
	x1 = q[0]-1;
	y1 = q[1]-1;
	x2 = q[2]-1;
	y2 = q[3]-1;

	int first = arr[x1][y1];
	int mini = first;

	for (int i = x1; i < x2; i++) {
		arr[i][y1] = arr[i + 1][y1];
		mini = min(mini, arr[i][y1]);
	}

	for (int i = y1; i < y2; i++) {
		arr[x2][i] = arr[x2][i + 1];
		mini = min(mini, arr[x2][i]);
	}

	for (int i = x2; i > x1; i--) {
		arr[i][y2] = arr[i - 1][y2];
		mini = min(mini, arr[i][y2]);
	}

	for (int i = y2; i > y1 + 1; i--) {
		arr[x1][i] = arr[x1][i - 1];
		mini = min(mini, arr[x1][i]);
	}

	arr[x1][y1 + 1] = first;
	return mini;

}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	makearr(rows, columns);
	for (int i = 0; i < queries.size(); i++) {
		int ret = rotate(queries[i]);
		answer.push_back(ret);
	}
	return answer;
}