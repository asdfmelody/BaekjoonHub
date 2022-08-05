#include <iostream>
#include <vector>
using namespace std;

long long k;
long long n;
vector<long long> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long maxi = 0;
    cin >> k >> n;
    for (long long i = 0; i < k; i++) {
        long long temp;
        cin >> temp;
        v.push_back(temp);
        if (temp > maxi) maxi = temp;
    }

    long long start = 1;
    long long end = maxi;
    long long max = -1;
    long long sum = 0;

    while (start <= end) {
        sum = 0;
        long long mid = (start + end) / 2;
        for (long long i = 0; i < k; i++) {
            sum += v[i] / mid;
        }
        if (sum < n) { end = mid - 1; }
        else {
            start = mid + 1;
            if (max < mid) max = mid;
        }
    }

    cout << max;

    return 0;
}