#include <iostream>
#include <string>
#include <queue>

using namespace std;

string circles[4]; //n 0 s 1
int k;
int ret;

void change(int topni, int dir) {
    string newcircle;
    if (dir == -1) {
        newcircle = circles[topni].substr(1,7) + circles[topni][0];
    }
    else {
        newcircle = circles[topni][7] + circles[topni].substr(0, 7);
    }
    circles[topni] = newcircle;
}

void dfs(int topni, int dir, char ns, bool spread) { // spread 0 왼 1 오
    if (topni < 0 || topni >= 4) return;
    char nowns;
    if (spread == 0) nowns = circles[topni][2];
    else nowns = circles[topni][6];
    if (ns == nowns) {
        return;
    }
    else {
        int nextdir = -dir;

        int nexttopni = topni;
        char nextns;
        if (spread == 0) {
            nexttopni--;
            nextns = circles[topni][6];
        }
        else
        {
            nexttopni++;
            nextns = circles[topni][2];
        }
        //circles[topni] 변경 시켜주기
        change(topni, nextdir);
        dfs(nexttopni, nextdir, nextns, spread);
    }
}

void turn(int topni, int dir) {
    //circles[topni] 변경 시켜주기
    char ns1 = circles[topni][6];
    char ns2 = circles[topni][2];
    change(topni,dir);

    dfs(topni - 1, dir, ns1, 0);
    dfs(topni + 1, dir , ns2, 1);
}

void cal() {
    if (circles[0][0] == '1') ret += 1;
    if (circles[1][0] == '1') ret += 2;
    if (circles[2][0] == '1') ret += 4;
    if (circles[3][0] == '1') ret += 8;
}

int main() {
    
    for (int i = 0; i < 4; i++) {
        cin >> circles[i];
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int topniNum, dir;
        cin >> topniNum >> dir;
        turn(topniNum - 1, dir);
    }

    cal();
    cout << ret;
    return 0;
}