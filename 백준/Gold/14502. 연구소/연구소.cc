#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int y, x;
};

int n, m;
int map[9][9];
int initVirus;
int initWall;
int minSpreadVirus = 0x7fffffff;
int spreadVirus; // 지역변수
int ret;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

queue<Node> q; // 첨에 initVirusIndex 넣어두고 q로 확산하면서 바이러스 확산 개수 찾기

//바이러스 몇개 확산했는지 확인 => 이미 2인 위치에서 시작.
void bfs() {
    int thisused[9][9]={0,};
    spreadVirus = 0;
    queue <Node> thisq = q;
    while (!thisq.empty()) {
        Node now = thisq.front(); thisq.pop();
        for (int i = 0; i < 4; i++) {
            int nexty = now.y + dy[i];
            int nextx = now.x + dx[i];
            if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
            if (thisused[nexty][nextx] == 1) continue;
            if (map[nexty][nextx]!= 0) continue;
            thisused[nexty][nextx] = 1;
            thisq.push({ nexty,nextx });
            spreadVirus++;
        }
    }
}

//dfs로 벽 세개 세우고 (0인것 중에 세개 고르기)
void dfs(int cy, int cx, int cnt) {
    if (cnt == 3) {
        // 종료 조건(벽 세개)에서 bfs하면서 바이러스 몇개 확산했는지 확인 
        bfs();
        if (minSpreadVirus > spreadVirus) {
            minSpreadVirus = spreadVirus; // => 확산된 바이러스 최소값 찾기..
        }
        return;
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 0) {
                map[y][x] = 3; //addedWall after
                dfs(y, x, cnt + 1);
                map[y][x] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int input;
            cin >> input; 
            map[y][x] = input;
            //처음에 2 바이러스 와 1 벽 의 개수 구하기 / 초기 바이러스 위치 구하기
            if (input == 1) {
                initWall++;
            }
            if (input == 2) {
                // 초기 바이러스 위치 구하기
                q.push({ y,x });
                initVirus++;
            }
        }
    }

    dfs(0, 0, 0);

    // 다 끝나고 n*m - 2의 개수 - 벽의 개수 - 3(추가된 벽개수) - 확산된 바이러스 최소 개수
    // => 확산된 바이러스 개수가 가장 적은 값을 찾기.
    ret = (n * m) - initVirus - initWall - 3 - minSpreadVirus;
    cout << ret;

    return 0;
}