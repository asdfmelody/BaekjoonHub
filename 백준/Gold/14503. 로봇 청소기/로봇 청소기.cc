#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[51][51];
int ret;

struct ROBOT {
    int y, x, dir;
};
ROBOT robot;

// 위 오 아 왼
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
    cin >> n >> m;
    cin >> robot.y >> robot.x >> robot.dir;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> map[y][x];
        }
    }
    
    queue<ROBOT> q;
    q.push(robot);

    while (!q.empty()) {
        ROBOT now = q.front(); q.pop();
        if (map[now.y][now.x] == 0) {
            map[now.y][now.x] = 2;
            ret++;
        }

        for (int i = 0; i < 4; i++) {
            ROBOT next;
            next.dir = (now.dir + 3 - i) % 4;
            next.y = now.y + dy[next.dir];
            next.x = now.x + dx[next.dir];
            if (next.y < 0 || next.x < 0 || next.y >= n || next.x >= m
                || map[next.y][next.x] != 0) continue;

            q.push(next);
            break;
        }

        if (q.empty()) {
            ROBOT next;
            next.dir = now.dir;
            next.y = now.y + dy[(next.dir + 2) % 4];
            next.x = now.x + dx[(next.dir + 2) % 4];
            if (next.y < 0 || next.x < 0 || next.y >= n || next.x >= m
                || map[next.y][next.x] == 1) break;
            q.push(next);
        }
    }

    cout << ret;
    return 0;
}