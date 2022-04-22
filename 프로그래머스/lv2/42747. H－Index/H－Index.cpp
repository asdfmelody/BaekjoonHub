#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int len = citations.size();
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < len; i++) {
        if(i+1 < citations[i]) answer++;
        
        if(i + 1 == citations[i]) {
            answer=i+1;
            break;
        }
		else if (i + 1 > citations[i]) {
			answer = i ;
			break;
		}
	}
	return answer;
}