#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<string> arr;
bool cmp(string a, string b)
{
	int al = a.length();
	int bl = b.length();
	if (al == bl) return a < b;
	return al < bl;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end(), cmp);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}
