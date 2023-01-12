#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    vector<string> kinds;
    int amount[31];
    
    for(int i=0;i<clothes.size();i++){
        string kind = clothes[i][1];
        int flag = 0;
        for(int k=0;k<kinds.size();k++){
            if(kinds[k] == kind) {
                flag = 1;
                amount[k] ++;
                break;
            }
        }
        if(flag == 0) {
            kinds.push_back(kind);
            amount[kinds.size()-1] = 1;
        }
    }
    
    for(int k=0;k<kinds.size();k++){
        answer *= amount[k] + 1;
    }
    
    return answer - 1;
}