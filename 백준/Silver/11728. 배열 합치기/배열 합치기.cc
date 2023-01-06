#include <iostream>
using namespace std;

int N, M;
int an[1000002];
int am[1000002];
int ans[2000004];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> an[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> am[i];
	}
	an[N] = 1000000001;
	am[M] = 1000000001;
	int pn = 0;
	int pm = 0;
	while (pn < N || pm < M) {
		if (an[pn] <= am[pm]) {
			ans[pn + pm] = an[pn];
			pn++;
		}
		else {
			ans[pn + pm] = am[pm];
			pm++;
		}
	}

	for (int i = 0; i < N + M; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}