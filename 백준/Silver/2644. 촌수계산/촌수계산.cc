#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int a, b;
int arr[101][101];
int used[101];
int res = 0;
int answer;

void bfs(int k) {
  if (k == b) {
    answer = res;
    return;
  }
  for(int i=1;i<n+1;i++){
    if (arr[k][i] == 0) continue;
    if (used[i] == 1) continue;
    used[i] = 1;
    res += 1;
    bfs(i);
    used[i] = 0;
    res -= 1;
  }

}

int main() {

	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
    cin >> x >> y;
    arr[x][y] = 1;
    arr[y][x] = 1;
	}

	bfs(a);

	(answer == 0) ? cout << -1 : cout << answer;

	return 0;
}