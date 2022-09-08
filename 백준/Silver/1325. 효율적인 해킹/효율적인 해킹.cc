#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> map[10001];
bool visited[10001];

struct Node
{
	int number, hackable; // 컴퓨터 번호, 해킹 가능한 컴퓨터 수
};

vector<Node> v;
int hacked = 1; //해킹 가능한 컴퓨터 수

void DFS(int v)
{
	visited[v] = true;

	for (int w = 0; w < map[v].size(); w++)
	{
		int nv = map[v][w];

		if (visited[nv] == 0)
		{
			visited[nv] = true;
			DFS(nv);
			hacked++;
		}
	}
}

void resetVisit()
{
	for (int i = 0; i <= N; i++)
	{
		visited[i] = 0;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		DFS(i);
		resetVisit();
		v.push_back({i, hacked});
		hacked = 1;
	}

	//해킹 가능한 최대 컴퓨터 수 구하기
	int maxHack = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].hackable > maxHack)
		{
			maxHack = v[i].hackable;
		}
	}

	//maxHack에 해당하는 컴퓨터 번호 모두 출력
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].hackable == maxHack)
		{
			cout << v[i].number << " ";
		}
	}

}
