#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    for(int i=0;i<s.size();i++){
        char last = '#';
        if(!st.empty()) last = st.top();
        char now = s[i];
        if(now == last) st.pop(); 
        else st.push(now);
    }
    if(st.empty())answer=1;
    return answer;
}