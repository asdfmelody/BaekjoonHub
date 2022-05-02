#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	vector<string> kinds;
	vector<int> count;

	for (int i = 0; i < clothes.size(); i++) {
		string kind;
		kind = clothes[i][1];

		int flag = 0;
		for (int k = 0; k < kinds.size(); k++) {
			if (kinds[k] == kind) {
				count[k]++;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			kinds.push_back(kind);
			count.push_back(1);
		}
	}

	for (int i = 0; i < count.size(); i++) {
		answer *= count[i] + 1;
	}

	return answer-1;
}