#define MAX 1000000000
#include<iostream>
#include<algorithm>
using namespace std;
int nums[101] = { 0, };
int mod_nums[101] = { 0, };

int GCD(int a, int b)
{
	int big, small;
	big = max(a, b);
	small = min(a, b);

	while (big != small)
	{
		if (big % small == 0)
			big = small;
		else
			big = big % small;

		swap(big, small);
	}

	return big;
}



int main()
{
	int n, i, k;
	int min;
	cin >> n;
	k = 0;
	min = MAX;
	for (i = 0; i < n; i++)
	{
		
		cin >> nums[i];
		if (nums[i] < min)
		{
			min = nums[i];
			k = i;
		}
	}

	swap(nums[0], nums[k]);

	mod_nums[1] = nums[1] - min;
	for (i = 2; i < n; i++)
	{
		mod_nums[i] = GCD(nums[i] - min,mod_nums[i-1]);
	}

	for (i = 2; i < mod_nums[n-1] / 2 + 1; i++)
	{
		if (mod_nums[n-1] % i == 0)
			cout << i << " ";
		
	}
	cout << mod_nums[n - 1];
	cout << endl;
	system("pause");
	return 0;
}