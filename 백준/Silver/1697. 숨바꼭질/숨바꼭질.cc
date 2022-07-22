#include <iostream>
#include <queue>

using namespace std;

int a,b;
int answer;
queue<int> q;
int used[100001];

void bfs(int k){
  q.push(k);
  used[k]=1;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    //if (now < 0 || now > 100000) continue;
    if (now == b) {
      answer = used[now];
        break;
    }

    if ((now * 2) <= 100000 && !used[now * 2]) {
      q.push(now * 2);
      used[now*2] = used[now] + 1;
    }
    if ((now + 1) <= 100000 && !used[now + 1]) {
      q.push(now + 1);
      used[now + 1] = used[now] + 1;
    }
    if ((now - 1) >= 0 && !used[now - 1]) {
      q.push(now - 1);
      used[now - 1] = used[now] + 1;
    }
  }
}

int main() {

  cin >> a >> b;
  bfs(a);
  cout << answer -1;
	return 0;
}