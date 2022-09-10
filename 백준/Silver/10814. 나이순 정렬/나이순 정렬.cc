#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
struct Node
{
	int age;
	string name;
	int order;
};
Node arr[100001];

bool cmp(Node a, Node b)
{
	if (a.age == b.age)
		return a.order < b.order;
	return a.age < b.age;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].age >> arr[i].name;
		arr[i].order = i;
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].age << " " << arr[i].name<<"\n";
	}
}