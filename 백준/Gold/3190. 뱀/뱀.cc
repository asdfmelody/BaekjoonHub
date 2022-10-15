#include <iostream>
#include <queue>

using namespace std;

int n, k, l;

int map[101][101]; // 1,1 부터 시작

struct Node {
    int y, x;
};

deque<Node> bam;

struct DIRECT {
    int sec, dir;
};

queue<DIRECT> dir; // 왼 -1 오 1

// 오 아 왼 위
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int nowDir;
int nowSec;
int bamLen = 1;

int main() {

    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        map[y][x] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int sec;
        char input;
        cin >> sec;
        cin >> input;
        if (input == 'L') dir.push({ sec,-1 });
        else dir.push({ sec,1 });
    }

    //while 1 무한반복 -> dir 일때마다 턴하고,, 사과잇으면 먹고
    // 종료 조건 : => 매반복마다 체크
    // 1. n*n 밖으로 나가면
    // 2. 나 자신을 박으면 

    // 뱀 : queue에 넣기!!!
    // 사과 박으면 push 만
    // 사과 안박으면 pop & push

    bam.push_front({ 1,1 }); // 최초
    DIRECT changeDir = dir.front(); dir.pop();

    while (1) {
        Node now = bam.front();
        int nexty, nextx;
        if (nowSec == changeDir.sec) { // 바꿔야할때

            nowDir = (4 + nowDir + changeDir.dir) % 4;

            if (dir.empty()) {
                changeDir = { 0,0 };
            }
            else {
                changeDir = dir.front(); dir.pop();
            }
        }
        // nowDir 안바꾸고 그대로 돌아갈때 -> 그대로
        nexty = now.y + dy[nowDir];
        nextx = now.x + dx[nowDir];

        nowSec++;

        //nexty,nextx 범위 초과일때, bam 안에 있는 애인지 확인 => 종료 : exit or 계속 : 사과 확인
        if (nexty <= 0 || nexty > n || nextx <= 0 || nextx > n) break;
        int flag = 0;
        for (int i = 0; i < bamLen; i++) {
            /*Node last = bam.back();
            if (bam[i].y == last.y && bam[i].x == last.x) continue;*/
            if (nexty == bam[i].y && nextx == bam[i].x) {
                flag = 1; break;
            }
        }
        if (flag == 1) break;


        // 사과 박았나 안박았나 확인해서 pop과 push 하기
        if (map[nexty][nextx] == 1) {//사과 박으면 push front
            bamLen++;
            bam.push_front({ nexty,nextx });
            map[nexty][nextx] = 0;
        }
        else {
            bam.push_front({ nexty,nextx });
            bam.pop_back();
        }

        //if (nowSec == 100) break;
    }

    cout << nowSec;

    return 0;
}