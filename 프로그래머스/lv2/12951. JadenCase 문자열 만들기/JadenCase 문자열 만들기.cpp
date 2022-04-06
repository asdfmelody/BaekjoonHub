#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int pos = 0;
	while (1) {
		if (s[pos] >= 'a' and s[pos] <= 'z') {
			s[pos] = s[pos] + 'A' - 'a';
		}

		int nextpos = s.find(' ', pos);
		if (nextpos == s.npos) nextpos = s.size();
		for (int i = pos + 1; i < nextpos; i++) {
			;
			if (s[i] >= 'A' and s[i] <= 'Z') {
				s[i] = s[i] + 'a' - 'A';
			}
		}

		if (nextpos == s.size()) break;
		pos = nextpos + 1;
	}


	return s;
}