#include<iostream>
using namespace std;

int main()
{
	int n, sum, cnt;

	cin >> n;
	if (n == 1)
	{
		cout << '1' << endl;
		return 0;
	}
	sum = 1;
	cnt = 1;

	while (sum < n)
	{
		sum += 6 * cnt;
		cnt++;
	}
	cout << cnt << endl;

	system("pause");
	return 0;
}