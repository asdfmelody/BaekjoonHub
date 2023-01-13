#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include<algorithm>

using namespace std;

struct node{
    int priority;
    int idx;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<node> q;
    
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
    }
    
    sort(priorities.begin(),priorities.end(),greater<int>());    
    
    node now = q.front(); q.pop();
    int order = 0;
    int i = 0;
    int len = priorities.size();
    while(1){
        if(now.priority == priorities[i % len]){
            order++;
            i++;
            if(location == now.idx){
                answer = order;
                break;
            }
            now = q.front(); q.pop();
        }else{
            q.push(now);
            now = q.front(); q.pop();
        }
    }
    
    return answer;
}