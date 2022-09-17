#include <iostream>
using namespace std;

int n;
struct Node{
	int left, right;
};
Node node[27];

void pre(char now)
{
	if (now == '.') return;
	cout << now;
	pre(node[now - 'A'].left);
	pre(node[now - 'A'].right);
}
void in(char now)
{
	if (now == '.') return;
	in(node[now - 'A'].left);
	cout << now;
	in(node[now - 'A'].right);
}
void post(char now)
{
	if (now == '.') return;
	post(node[now - 'A'].left);
	post(node[now - 'A'].right);
	cout << now;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char now, l, r;
		cin >> now >> l >> r;
		node[now - 'A'].left = l;
		node[now - 'A'].right = r;
	}
	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
}