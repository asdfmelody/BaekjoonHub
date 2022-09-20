#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int now = 1;
int cnt = 1;
int endCnt;
int used[5001];
vector<int> answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	while (1) {
		if (used[now] == 1) {
		}
		else {
			if (cnt == k) {
				answer.push_back(now);
				endCnt++;
				used[now] = 1;
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		// 마무리 (다음을 위해)
		now++;
		if (now == n+1) now = 1;
		if (endCnt == n) break;
	}
	cout << "<";
	for (int i = 0; i < n-1; i++) {
		cout << answer[i] << ", ";
	}
	cout << answer[n - 1];
	cout << ">";
	return 0;
}