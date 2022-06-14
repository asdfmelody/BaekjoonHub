#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int workday(int progress, int speed){
    int ret = ceil((double)(100 - progress)/(double)speed);
    return ret;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> left;
    int len = progresses.size();
    // left days
    for(int i=0;i<len;i++){
        left.push_back(workday(progresses[i],speeds[i]));
        //cout<<left[i];
    }
    //
    int front = left[0];
    int cnt=1;
    for(int i=1;i<len;i++){
        if(front < left[i]) {
            answer.push_back(cnt);
            front = left[i];
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    answer.push_back(cnt);
    return answer;
}