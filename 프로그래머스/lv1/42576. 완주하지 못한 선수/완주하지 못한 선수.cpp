#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    int len = completion.size();
    bool found = 0;
    for(int i=0;i<len;i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            found = 1;
            break;
        }
    }
    if(found == 0) answer = participant[len];
    return answer;
}