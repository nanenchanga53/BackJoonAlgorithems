#include <iostream>
#include <stdio.h>
#include <deque>
#include <queue>
#include <utility>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		deque <pair<int, int>> dq(n, make_pair(0, 0));
		priority_queue <int> pq;
		for (int i = 0; i < n; i++)
		{
			cin >> dq[i].first;
			pq.push(dq[i].first);
		}
		dq[m].second = 1;
		int count = 1;
		while (1)
		{
			int high = pq.top();
			int first = dq[0].first;

			if (high == first)
			{
				if (dq[0].second)
					break;
				count++;
				pq.pop();
			}
			else
				dq.push_back(dq[0]);

			dq.pop_front();
		}
		cout << count << endl;
	}
	system("pause");

	return 0;
}