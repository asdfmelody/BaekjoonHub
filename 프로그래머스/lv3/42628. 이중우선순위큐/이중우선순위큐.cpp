#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, less<int>> great_pq;
priority_queue<int, vector<int>, greater<int>> less_pq;

void init(){
    while(!great_pq.empty()) great_pq.pop();
    while(!less_pq.empty()) less_pq.pop();
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    int cnt = 0;
    
    for(int i=0;i<operations.size();i++) {
        if(operations[i][0] == 'I') {
            int num = stoi(operations[i].substr(1));
            great_pq.push(num);
            less_pq.push(num);
            cnt++;
        }else{
            if(cnt <= 1){
                init();
                cnt = 0;
            }else{
                if(operations[i][2] == '-') {
                    less_pq.pop();
                }
                else{
                    great_pq.pop();
                }
                cnt--;
            }
        }
    }
    
    if(cnt <= 0){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(great_pq.top());
        answer.push_back(less_pq.top());
    }
    
    return answer;
}