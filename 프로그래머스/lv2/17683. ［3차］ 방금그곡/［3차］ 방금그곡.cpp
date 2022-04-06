#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct song {
	int idx;
	int duration;
	string name;
	string fullMelody;
};

vector<song> songs;

bool operator<(song left, song right) {
	if (left.duration > right.duration) return true;
	if (left.duration < right.duration) return false;
	
	return left.idx < right.idx;
}

string chihwan(string m) {
	string answer;
	int size = m.size();
	for (int k = 0; k < size; k++) {
		if (k < (size - 1) and m[k + 1] == '#') {
			string temp = m.substr(k, 2);

			//치환
			if (temp == "C#") temp = 'H';
			else if (temp == "D#") temp = "I";
			else if (temp == "F#") temp = "J";
			else if (temp == "G#") temp = "K";
			else if (temp == "A#") temp = "L";
			k++;

			answer += temp;
		}
		else {
			string temp = "";
			temp += m[k];

			answer += temp;
		}
	}
	return answer;

}

void parsing(vector<string> mi) {
	int pos = 0;
	for (int i = 0; i < mi.size(); i++) {
		string s = mi[i];
		int starth = stoi(s.substr(0, 2));
		int startm = stoi(s.substr(3, 2));
		int endh = stoi(s.substr(6, 2));
		int endm = stoi(s.substr(9, 2));

		//duration 구하기
		int duration = ((endh - starth) * 60) + endm - startm;

		int findPos = s.find(",", 12);
		string name = s.substr(12, findPos - 12);

		//fullMelody 구하기
		string fullMelody;
		string inputMelody = s.substr(findPos + 1);

		//inputMelody 치환해서 fullMelody에 넣기.
		fullMelody=chihwan(inputMelody);

		int fullsize = fullMelody.size();

		if (fullsize >= duration) { //음악재생시간이 더 적을때..? -> tc 30해결..
			fullsize = duration;
			string realMelody = fullMelody.substr(0, duration);
			fullMelody = realMelody;
		}

		int inputsize = fullsize;
		int idx = 0;

		while (fullsize < duration) {
			fullMelody+=fullMelody[idx];
			fullsize++;
			if (idx >= inputsize) idx = 0;
			idx++;
		}

		songs.push_back({ i,duration,name,fullMelody });
	}
}

string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	vector<song> candidates;

	parsing(musicinfos);

	//m 치환하기
	string music = chihwan(m);

	for (int i = 0; i < songs.size(); i++) {

		int Found = 0; //찾으면 1로 변함

		int minsize = music.size(); //비교시 마지막 # 있나 없나 할때 씀..

		// 아랫줄 주석처리하니까 7~9 12~15 17~18 21~24 성공함..ㅠㅠ
		//m크키가 더 클때 m자르기
		//if (minsize > songs[i].duration) {
		//	music = music.substr(0, songs[i].duration);
		//	minsize = songs[i].duration;
		//}

		string s = songs[i].fullMelody;

		int pos = 0;
		int nextpos = s.find(music, pos);
		if (nextpos >= 0) { //찾았을때
			//answer = songs[i].name;
			Found = 1;
		}
		if (Found == 1) {
			candidates.push_back(songs[i]);
		}
	}
	
	if (candidates.size() == 0) return answer;
	sort(candidates.begin(), candidates.end());
	return candidates[0].name;
}

int main() {
	string answer = solution("CC#BCC#BCC#BCC#B", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" });

	return 0;
}
