#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;

int main()
{
	deque<int> qu;

	char order[11];
	int n, k;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> order;

		if (!strcmp(order, "push_front"))
		{
			cin >> k;
			qu.push_front(k);
		}

		if (!strcmp(order, "push_back"))
		{
			cin >> k;
			qu.push_back(k);
		}

		if (!strcmp(order, "pop_front"))
		{
			if (qu.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				k = qu.front();
				qu.pop_front();
				cout << k << endl;
			}
		}

		if (!strcmp(order, "pop_back"))
		{
			if (qu.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				k = qu.back();
				qu.pop_back();
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

		if (!strcmp(order, "back"))
		{
			if (qu.empty())
				cout << -1 << endl;
			else
			{
				k = qu.back();
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
	}

	return 0;
}