#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int indexRule(vector<string> words) {
	string befWord = words[0];
	for (int i = 1; i < words.size(); i++) {
		int beflen = befWord.size();
		if (befWord[beflen - 1] == words[i][0]) befWord=words[i];
		else return i;
	}
	return -1;
}

int indexRepeat(vector<string> words) {
	vector<string> saidWords;
	saidWords.push_back(words[0]);
	int ret = -1;
	int flag = 0;

	for (int w = 1; w < words.size(); w++) {
		string word = words[w];
		
		for (int i = 0; i < saidWords.size();i++) {
			if (word == saidWords[i]) {
				ret = w;
				flag = 1;
				break;
			}
		}
		if (flag == 0)saidWords.push_back(word);
		else break;
	}
	return ret;
}

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	int idx = 0;

	// 반복된 단어 말할 때
	int idxRepeat = indexRepeat(words);

	//  끝말잇기 안될 때
	int idxRule = indexRule(words);

	if (idxRepeat == -1 && idxRule == -1) return { 0,0 };
	else if (idxRepeat == -1) idx = idxRule;
	else if (idxRule == -1) idx = idxRepeat;
	else idx = min(idxRepeat, idxRule);

	int seq = (idx % n) + 1;
	int round = (idx / n) + 1;
	answer = { seq,round };

	return answer;
}
