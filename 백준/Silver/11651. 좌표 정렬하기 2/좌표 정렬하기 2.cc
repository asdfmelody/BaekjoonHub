#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
};
bool operator< (Node left, Node right) {
	if (left.y < right.y) return 1;
	if (left.y > right.y) return 0;
	return left.x < right.x;

}
int main() {
	int n;
	cin >> n;
	vector<Node> arr;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({ x,y });
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}
	return 0;
}