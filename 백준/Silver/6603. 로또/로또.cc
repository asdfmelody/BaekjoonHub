#include <iostream>
#include <vector>
using namespace std;

int S[13];
int lotto[6];
int k;

void run(int start, int level) {
	if (level == 6) {
		for (int i = 0; i < 6; i++) cout << lotto[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i < k; i++) {
		lotto[level] = S[i];
		run(i + 1, level + 1);
	}
}
int main(void) {
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> S[i];
		}
		run(0, 0);
		cout << endl;
	}
}