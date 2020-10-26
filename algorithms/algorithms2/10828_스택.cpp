#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	stack<int> st;

	char order[6];
	int n, k;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> order;

		if (!strcmp(order, "push"))
		{
			cin >> k;
			st.push(k);
		}

		if (!strcmp(order, "pop"))
		{
			if (st.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				k = st.top();
				st.pop();
				cout << k << endl;
			}
		}

		if (!strcmp(order, "size"))
		{
			k = st.size();
			cout << k << endl;
		}

		if (!strcmp(order, "empty"))
		{
			k = st.empty();
			cout << k << endl;
		}

		if (!strcmp(order, "top"))
		{
			if (st.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				k = st.top();
				cout << k << endl;
			}
		}
	}

	return 0;
}