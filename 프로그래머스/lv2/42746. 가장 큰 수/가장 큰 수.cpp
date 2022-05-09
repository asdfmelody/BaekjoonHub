#include <string>
#include <vector> 
#include <algorithm>

using namespace std;

struct Node {
	string str; // 원래 숫자를 string 형으로 바꾼것
	int changedint; // 원래 숫자에 첫 숫자 추가한것 (3자리수)
};

int change(string str) { // 3자리수 int형으로 바꾸는 함수
	while (str.size() < 3) {
		str += str[0];
	}
	return stoi(str);
}

bool operator<(Node left, Node right) { 
	//changedint가 더 큰것 먼저!
	if (left.changedint > right.changedint) return true;
	if (left.changedint < right.changedint) return false;
	return left.str.back() > right.str.back(); // tc 12~14 (ex. 232, 23)

}

string solution(vector<int> numbers) {
	string answer = "";
	vector<Node> map;
	int flag0 = 0;
	int flag1000 = 0;
	for (int i:numbers) {
		if (i == 0) {
			flag0 ++; // 0 은 맨 마지막에 넣어야함
			continue;
		}
		else if (i == 1000) { //1000은 0이 있을 경우 0 앞
			flag1000 ++;
			continue;
		}
		string str = to_string(i);
		int changednum = change(str);
		map.push_back({ str, changednum });
	}

	sort(map.begin(), map.end());
	for (int i = 0; i < map.size(); i++) {
		answer += map[i].str;
	}

	//tc 1~6 (0 이나 1000 중복될경우)
	for (int i = 0; i < flag1000;i++) answer += "1000";
	for (int i = 0; i < flag0; i++) answer += "0";

	// tc 11 (ex. 0, 0, 0)
	if (flag0 == numbers.size()) return "0";
	return answer;
}