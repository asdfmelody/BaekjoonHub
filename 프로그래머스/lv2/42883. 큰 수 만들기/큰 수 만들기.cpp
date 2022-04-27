#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int start = 0;
	int maxIndex = -1;
	int flag = 0;
	while (1) {
		char max = '0';
		if (k == 0) break;
		for (int i = start; i <= start + k; i++) {
			if (i >= number.length()) {
				flag = 1;
				break;
			}
			if (max < number[i]) {
				max = number[i];
				maxIndex = i;
			}
		}
		if (flag == 1) break;
		k -= maxIndex - start;
		start = maxIndex + 1;
		answer += max;
	}
	if (flag == 1) {
		string nanswer = "";
		for (int i = 0; i < number.length()- k; i++) {
			nanswer += number[i];
		}
		answer = nanswer;
		return answer;
	}

	for (int i = maxIndex + 1; i < number.length(); i++) {
		answer += number[i];
	}

	return answer;
}