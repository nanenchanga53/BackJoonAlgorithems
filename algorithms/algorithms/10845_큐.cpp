#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	queue<int> qu;

	char order[6];
	int n, k;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> order;

		if (!strcmp(order, "push"))
		{
			cin >> k;
			qu.push(k);
		}

		if (!strcmp(order, "pop"))
		{
			if (qu.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				k = qu.front();
				qu.pop();
				cout << k << endl;
			}
		}

		if (!strcmp(order, "front"))
		{
			if (qu.empty())
				cout << -1 << endl;
			else
			{
				k = qu.front();
				cout << k << endl;
			}
		}

		if (!strcmp(order, "size"))
		{
			k = qu.size();
			cout << k << endl;
		}

		if (!strcmp(order, "empty"))
		{
			k = qu.empty();
			cout << k << endl;
		}

		if (!strcmp(order, "back"))
		{
			if (qu.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				k = qu.back();
				cout << k << endl;
			}
		}
	}

	return 0;
}