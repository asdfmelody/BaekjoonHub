#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	int len = arr.size();

	for (int i = 0; i < len; i++) {
		cout << arr[i]<< " ";
	}

	return 0;
}