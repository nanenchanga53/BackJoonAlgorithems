#include<iostream>
using namespace std;

int n;
long long cost[100001] = { 0, };
long long len[100001] = { 0, };
long long res = 0;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> len[i];
	}

	cin >> cost[0];
	for (int i = 1; i < n; i++)
	{
		cin >> cost[i];
		if (cost[i - 1] < cost[i])
			cost[i] = cost[i - 1];
	}

	for (int i = 0; i < n - 1; i++)
	{
		res +=cost[i] * len[i];
	}

	cout << res << endl;

	return 0;

}