#include <string>
#include <vector>
using namespace std;
 
string solution(int n) 
{
    string answer = "";
    string str[] = { "1" , "2", "4" };
    while(n > 0)
    {
        answer = str[(n-1) % 3]+ answer;
        if(n % 3 == 0) n = (n / 3) - 1;
        else n = n / 3;
    }
    return answer;
}