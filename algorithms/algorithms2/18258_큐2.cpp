#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
#include<queue>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n,num;
	string op;
	queue<int> que;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> op;
		if (op == "push")
		{
			cin >> num;
			que.push(num);
		}
		else if (op == "pop")
		{
			if (que.empty())
				cout << -1 << '\n';
			else
			{
				cout << que.front() << '\n';
				que.pop();
			}
		}
		else if (op == "size")
		{
			cout << que.size() << '\n';
		}
		else if (op == "empty")
		{
			cout << que.empty() ? 1 : 0;
			cout << '\n';
		}
		else if (op == "front")
		{
			if (que.empty())
				cout << -1 << '\n';
			else
				cout << que.front() << '\n';
		}
		else if (op == "back")
		{
			if (que.empty())
				cout << -1 << '\n';
			else
				cout << que.back() << '\n';
		}
	}

	return 0;
}