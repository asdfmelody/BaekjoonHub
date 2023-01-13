#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> bapo; // 배포 날짜
    
    int len = progresses.size();
    
    for(int i=0;i<len;i++){
        int left_progress = 100 - progresses[i];
        int days = ceil((float)left_progress / (float)speeds[i]); // 올림해야됨.
        bapo.push_back(days);
    }
    
    int d_day = bapo[0];
    int cnt = 1;
    for(int i=1;i<len;i++){
        if(d_day >= bapo[i]) cnt++;
        else{
            answer.push_back(cnt);
            d_day = bapo[i];
            cnt = 1;
        }
    }
    
    answer.push_back(cnt);
    
    
    return answer;
}