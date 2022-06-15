#include <string>
#include <vector>

using namespace std;

int answer=0;
int Target;
int Len;
vector<int> Numbers;

void dfs(int n,int level){
    if(level == Len){
        if(n == Target) answer++;
        return;
    } 
    dfs(n+Numbers[level],level+1);
    dfs(n-Numbers[level],level+1);
}

int solution(vector<int> numbers, int target) {
    Numbers=numbers;
    Target= target;
    Len = numbers.size();
    dfs(0,0);
    return answer;
}