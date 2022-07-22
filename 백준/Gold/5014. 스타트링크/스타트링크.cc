#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
queue<int> q;
int used[1000001];
int answer = 1;

void bfs() { 
  q.push(S); 
  used[S] = 1;

  while(!q.empty()){
    S = q.front();
    q.pop();

    //up
    int next = S + U;
    if(next > 0 && next<=F){
      if (used[next] == 0) {
      used[next] = used[S] + 1;
      q.push(next);
      }
    }
    if (S == G) {
      answer = 0;
      break;
    }

    //down
    next = S - D;
    if (next > 0 && next <= F) {
      if (used[next] == 0){
      used[next] = used[S] + 1;
      q.push(next);
      }
    }
    if (S == G) {
      answer = 0;
      break;
    }
  }
}

int main() {
  cin >> F >> S >> G >> U >> D;

  bfs();
  if (answer) cout << "use the stairs";
  else
    cout << used[G] - 1;
	return 0;
}