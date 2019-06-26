#include<iostream>
using namespace std;
int main()
{
	int n, res, cnt;
	int ten, one;
	cin >> n;
	res = n;
	cnt = 0;

	while (1)
	{
		cnt++;
		ten = res / 10;
		one = res % 10;
		res = one * 10 + ((ten + one) % 10);
		if (res == n)
			break;
	}
	cout << cnt;

	return 0;
}