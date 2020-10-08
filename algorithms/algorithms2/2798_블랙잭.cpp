#include<iostream>
using namespace std;


int main()
{
	int n, m;
	int nums[300001], sum;
	int max = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum = nums[i] + nums[j] + nums[k];
				if (sum <= m && sum > max)
				{
					max = sum;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}