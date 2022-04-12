#include <string>
#include <vector>

using namespace std;

int removeCnt = 0;
int n = 0;



string change(string s) {
	//1개수 구하기
	int cnt1 = 0;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == '1') cnt1++;
	}
	removeCnt += len -cnt1;
	n++;
	//cnt1 2진수로 변환
	string answer = "";
	while (cnt1 > 0) {
		answer = to_string(cnt1 % 2) + answer;
		cnt1 /= 2;
	}
	return answer;
}

vector<int> solution(string s) {

	string str=s;
	while (1) {
		str = change(str);
		if (str == "1") break;
	}

	vector<int> answer = { n , removeCnt };
	return answer;
}