#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	int k;
	vector<int> arr;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int input;
		cin >> input;
		if (input == 0) {
			arr.pop_back();
		}
		else {
			arr.push_back(input);
		}
	}
	int answer = accumulate(arr.begin(),arr.end(),0);
	cout << answer;
	return 0;
}