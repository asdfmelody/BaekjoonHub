#include <iostream>

using namespace std;

int n, m;
int map[501][501];

//위 오 아 왼
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int mem[501][501];

struct Node {
    int y, x;
};

Node rem[4];

int maxRet = -1;

void dfs(int cy, int cx, int cnt,int flag) {
    if (cnt == 4) {
        //최대값 구하기
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            sum += map[rem[i].y][rem[i].x];
        }
        if (maxRet < sum) maxRet = sum;
        return;
    }
    if (cnt == 3 && flag == 0) {
        if (rem[0].x == rem[1].x && rem[1].x == rem[2].x && rem[2].x == rem[0].x) {
            rem[3].y = rem[1].y;
            rem[3].x = rem[1].x - 1;
            dfs(0, 0, 4, 1);
            rem[3].x = rem[1].x + 1;
            dfs(0, 0, 4, 1);
        }
        if (rem[0].y == rem[1].y && rem[1].y == rem[2].y && rem[2].y == rem[0].y) {
            rem[3].x = rem[1].x;
            rem[3].y = rem[1].y - 1;
            dfs(0, 0, 4, 1);
            rem[3].y = rem[1].y + 1;
            dfs(0, 0, 4, 1);
        }

    }
    rem[cnt].y = cy;
    rem[cnt].x = cx;
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (mem[ny][nx] != 0) continue;
        mem[ny][nx] = 1;
        dfs(ny, nx, cnt + 1,flag);
        mem[ny][nx] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }

    // dfs 로 4번 되면 종료 조건 : 최대값 구하기
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            mem[y][x] = 1;
            dfs(y, x, 0,0);
            mem[y][x] = 0;
        }
    }

    cout << maxRet;

    return 0;
}