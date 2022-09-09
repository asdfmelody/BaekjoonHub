#include <iostream>
using namespace std;

int N;
struct Node
{
	int x, y;
};
Node node[51];

int run(int n)
{
	int ret = 0;
	Node now = node[n];
	for (int i = 0; i < N; i++)
	{
		if (now.x < node[i].x && now.y < node[i].y) ret++;
	}
	return ret + 1;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> node[i].x >> node[i].y;
	}
	for (int i = 0; i < N; i++)
	{
		cout << run(i) << " ";
	}

}
