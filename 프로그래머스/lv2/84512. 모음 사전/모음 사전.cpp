#include <string>
#include <vector>

using namespace std;

int answer = 0;
string alpha[5] = { "A","E","I","O","U" };
int cnt = 0;
string Word;
void dfs(string w) {
	if (w.size() > 5) return;
	cnt++;
	if (w == Word) answer = cnt;
	for (int i = 0; i < 5; i++) {
		string next = w + alpha[i];
		dfs(next);
	}
}

int solution(string word) {
	Word = word;
	for (int i = 0; i < 5; i++) {
		dfs(alpha[i]);
	}
	return answer;
}