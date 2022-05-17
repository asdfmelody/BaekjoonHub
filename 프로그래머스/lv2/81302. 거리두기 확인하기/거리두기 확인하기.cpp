#include <string>
#include <vector>

using namespace std;

vector<string> Room;

struct person {
	int r, c;
};

int check(person person1, person person2) { //가림막 있으면 1, 없으면 0
	if (person1.r == person2.r) {
		int c = (person1.c + person2.c) / 2;
		if (Room[person1.r][c] == 'X') return 1;
	}
	else if (person1.c == person2.c) {
		int r = (person1.r + person2.r) / 2;
		if (Room[r][person1.c] == 'X') return 1;
	}
	else {
		if ((Room[person1.r][person2.c] == 'X') && (Room[person2.r][person1.c] == 'X')) return 1;
	}
	return 0;
}

int cha(person person1, person person2) {
	int R = person1.r - person2.r;
	if (R < 0) R *= -1;
	int C = person1.c - person2.c;
	if (C < 0) C *= -1;
	return R + C;
}

int find(vector<string> room) {
	int ret = 1;
	vector<person> people;
	Room.clear();
	for (int y = 0; y < 5; y++) {
		Room.push_back(room[y]);
		for (int x = 0; x < 5; x++) {
			if (room[y][x] == 'P') {
				people.push_back({ y, x });
			}
		}
	}

	for (int i = 0; i < people.size(); i++) {
		person person1 = people[i];
		for (int j = i + 1; j < people.size(); j++) {
			person person2 = people[j];
			int ch = cha(person1, person2);
			if (ch == 0) continue;
			else if (ch == 1) return 0;
			else if (ch == 2) { // 가림막 있는지 확인 
				if (check(person1, person2)) continue; //가림막이 있으면(1) continue
				else return 0;
			}
		}
	}

	return ret;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int i = 0; i < places.size(); i++) {
		vector<string> room = places[i];
		answer.push_back(find(room));
	}
	return answer;
}