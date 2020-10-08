#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second)
	{
		return true;
	}
	else if (a.second == b.second)
	{
		if (a.first < b.first)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	vector<pair<int, int>> arr;
	int n;
	int x, y;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}
	sort(arr.begin(), arr.begin() + n, cmp);

	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", arr[i].first, arr[i].second);
	}

	return 0;
}