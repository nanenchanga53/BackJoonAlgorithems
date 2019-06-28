#include<iostream>
using namespace std;
int main()
{
	int i, j, n, sum;
	char m[101];
	cin >> n >> m;

	sum = 0;

	for (i = 0; i < n; i++)
	{
		sum += m[i] - '0';
	}

	cout << sum << endl;

	return 0;

}