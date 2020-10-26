#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
#include<stack>
using namespace std;

int n;
stack<int> nums;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (!nums.empty() && num == 0)
		{
			nums.pop();
		}
		else
		{
			nums.push(num);
		}
	}

	int sum = 0;

	while(!nums.empty())
	{
		sum += nums.top();
		nums.pop();
	}

	cout << sum << '\n';

	return 0;
}