#include <string>
#include <vector>
#include <queue>

using namespace std;

int calc(int a, int b){
    return a + b + b;
}

int solution(vector<int> scoville, int K) {
    int sum=0;
    int answer = 0;
    priority_queue <int,vector<int>,greater<int>> pq; //작은수부터 빠져나옴
    for(int i=0;i<scoville.size();i++) pq.push(scoville[i]);
    
    while(1){
        if(pq.size() < 2) break;
        int least1 = pq.top();
        pq.pop();
        if(least1 >= K) break;
        int least2 = pq.top();
        pq.pop();

        sum=calc(least1,least2);
        answer++;
        pq.push(sum);
    }
    if (sum < K) answer = -1 ; 
    return answer;
}