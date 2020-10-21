#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int minTimes = 0;
	int times[1001] = { 0, }, sumTimes[1001] = { 0, };
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> times[i];
	}

	sort(times, times + n);

	sumTimes[0] = times[0];

	for (int i = 1; i < n; i++)
	{
		sumTimes[i] = sumTimes[i - 1] + times[i];
	}

	for (int i = 0; i < n; i++)
	{
		minTimes += sumTimes[i];
	}

	cout << minTimes;

	return 0;
}