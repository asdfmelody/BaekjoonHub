#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<string> arr;

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end(),cmp);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	int len = arr.size();
	for (int i = 0; i < len; i++) {
		cout << arr[i]<<"\n";
	}
	
	
	return 0;
}