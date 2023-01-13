#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int len = arr.size();
    
    answer.push_back(arr[0]);
    
    for(int i=1;i<len;i++){
        if(arr[i] != answer.back()) answer.push_back(arr[i]);
    }

    return answer;
}