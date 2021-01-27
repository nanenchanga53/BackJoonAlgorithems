#include<iostream>
#include<stack>
using namespace std;

int n, a[1000001], res[1000001];
stack<int> st;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		res[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	
	for (int i = 0; i < n; i++)
	{

		while (!st.empty() && a[st.top()] < a[i])
		{
			res[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i] << ' ';
	}

	return 0;

}