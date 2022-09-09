#include <iostream>
#include <queue>
using namespace std;

int T;
int l;
struct Node
{
	int y, x;
};
Node now;
Node dest;

int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int used[301][301];

void bfs(Node in)
{
	queue<Node> q;
	q.push(in);
	used[in.y][in.x] = 1;
	while (1)
	{
		Node n = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = n.y + dy[i];
			int nx = n.x + dx[i];
			if (ny < 0 || ny >= l || nx < 0 || nx >= l) continue;
			if (used[ny][nx] != 0) continue;
			used[ny][nx] = used[n.y][n.x] + 1;
			if (ny == dest.y && nx == dest.x) return;
			q.push({ny, nx});
		}
	}
}
void initUsed()
{
	for (int y = 0; y < l; y++)
	{
		for (int x = 0; x < l; x++)
		{
			used[y][x] = 0;
		}
	}
}
int main()
{
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> l;
		cin >> now.y >> now.x;
		cin >> dest.y >> dest.x;
		if (now.y == dest.y && now.x == dest.x)
		{
			cout << 0 << "\n";
			continue;
		}
		initUsed();
		bfs(now);
		cout << used[dest.y][dest.x] -1 << "\n";
	}
}
