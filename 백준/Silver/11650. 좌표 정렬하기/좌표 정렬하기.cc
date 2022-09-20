#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct Node{
	int x,y;
};
vector <Node> arr;

bool cmp(Node a, Node b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({ x,y });
	}

	sort(arr.begin(), arr.end(), cmp);


	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}

	return 0;
}