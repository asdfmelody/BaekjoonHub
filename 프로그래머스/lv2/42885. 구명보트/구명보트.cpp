#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	deque<int> dpeople(people.begin(),people.end());

	while (!dpeople.empty()) {
		int front = dpeople.front();
		int back = dpeople.back();

		if (front + back > limit) {
			answer += 1;
			dpeople.pop_back();
		}
		else {
			answer += 1;
			dpeople.pop_back();
			if (dpeople.empty()) break; // 남은 숫자가 50인경우
			dpeople.pop_front();
		}
	}

	return answer;
}