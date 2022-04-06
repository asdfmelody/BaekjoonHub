#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		vector<int> flags(skill.size(), 0);
		int flag = 0;
		string now = skill_trees[i];
		for (int k = 0; k < now.size(); k++) {
			for (int s = 0; s < skill.size(); s++) {
				if (now[k] == skill[s]) {
					flags[s] = 1;
					if (s == 0) continue;
					else if (flags[s - 1] == 1) continue;
					else {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1)continue;
		else answer++;
	}
	return answer;
}