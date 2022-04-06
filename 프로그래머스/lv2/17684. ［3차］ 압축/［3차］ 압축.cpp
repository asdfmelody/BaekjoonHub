#include <string>
#include <vector>

using namespace std;

string arr[1050];

void initial() {
	for (int i = 1; i <= 26; i++) {
		arr[i] = 'A' + i - 1;
	}
}

int isValid(string str,int last) {
	for (int i = last; i >= 1; i--) {
		if (arr[i] == str) {
			return i; //존재함 (1이상의 숫자)
		}
	}
	return 0;//존재 안함
}

vector<int> solution(string msg) {
	vector<int> answer;
	int last = 26; //26~1;
	initial();
	int now = 0;
	int flag = 0;
	while (1) {

		string str = "";
		int realnum; //이전의 값
		while (1) {
			if (now >= msg.size()) {
				flag = 1;
				break;
			}
			str += msg[now];
			int num = isValid(str, last);
			if (num == 0) { //사전 추가
				last++;
				arr[last] = str;
				break;
			}
			now++;
			realnum = num;
		}
		answer.push_back(realnum);
		if (flag == 1)break;

	}
	return answer;
}