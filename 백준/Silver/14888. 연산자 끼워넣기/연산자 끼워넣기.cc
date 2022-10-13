#include <iostream>
using namespace std;

int n;
int input[12];
int op[4];

int mymax = - 0x7fffffff;
int mymin = 0x7fffffff;

void re(int result, int idx) {
    if (idx == n-1) {
        if (result > mymax) mymax = result;
        if (result < mymin) mymin = result;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] != 0) {
            op[i]--;
            if (i == 0) re(result + input[idx+1], idx + 1);
            else if (i == 1) re(result - input[idx+1], idx + 1);
            else if (i == 2) re(result * input[idx+1], idx + 1);
            else if (i == 3) re(result / input[idx+1], idx + 1);
            op[i]++;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    re(input[0], 0);
    cout << mymax << "\n" << mymin;
    return 0;
}