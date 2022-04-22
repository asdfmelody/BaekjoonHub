#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
        
    // x+y = (brown+4)/2 
    // x*y = brown+yellow
    // 이차방정식 근의 공식
    
    int x = ((brown + 4) / 2 + sqrt(pow(((brown + 4 ) / 2 ),2) - 4 * (brown + yellow)))/2;
    int y = ((brown + 4) / 2 - sqrt(pow(((brown + 4 ) / 2 ),2) - 4 * (brown + yellow)))/2;
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}