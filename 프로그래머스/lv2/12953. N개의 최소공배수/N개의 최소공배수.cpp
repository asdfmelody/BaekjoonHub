#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int tmp, n;
 
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int solution(vector<int> arr) {
    if(arr.size() ==1 )return arr[0];
    
    int next = arr[0]*arr[1]/gcd(arr[0],arr[1]);
    for(int i=2;i<arr.size();i++){
        next = next*arr[i]/gcd(next,arr[i]);
    }
    return next;
}