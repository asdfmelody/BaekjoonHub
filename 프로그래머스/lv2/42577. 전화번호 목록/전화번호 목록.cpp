#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    int len = phone_book.size();
    for(int i=1;i<len;i++){
        int front_size = phone_book[i-1].size();
        if(front_size < phone_book[i].size() && phone_book[i-1][0] == phone_book[i][0]){
            bool right = true;
            for(int j=1;j<front_size;j++){
                if(phone_book[i-1][j] != phone_book[i][j]) {
                    right = false;
                    break;
                }
            }
            if(right == true) {
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}