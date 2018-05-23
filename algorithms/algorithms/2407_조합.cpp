#include<iostream>
#include<iomanip>
using namespace std;

int nums[10001] = { 0 };

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

void find_coe(int n, int k)
{
	nums[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		nums[0] *= (n - i + 1);
		for (int j = 1; j < 10000; j++)
		{
			nums[j] *= (n - i + 1);
			nums[j] += nums[j - 1] / 100;
			nums[j - 1] %= 100;
		}

		for (int j = 9999; j > 0; j--)
		{
			nums[j - 1] += 100 * (nums[j] % i);
			nums[j] /= i;
		}
		nums[0] /= i;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	if (k < 0 || k > n)
		cout << 0 << endl;
	else
	{
		find_coe(n, k);
		int x;
		for (x = 9999; x >= 0; x--)
			if (nums[x] != 0)
				break;

		cout << nums[x];
		for (x = x - 1; x >= 0; x--)
			cout << setw(2) << setfill('0') << nums[x];

		cout << endl;
	}
	system("pause");

	return 0;
}