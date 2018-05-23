#include<iostream>
using namespace std;

int coefficient[1001][1001] = { 0, };

void make_coe()
{
	coefficient[0][0] = 1;
	coefficient[1][0] = coefficient[1][1] = 1;

	for (int i = 2; i <= 1000; i++)
	{
		coefficient[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			coefficient[i][j] = (coefficient[i - 1][j - 1] + coefficient[i - 1][j]) % 10007;
		}
	}
}

int main()
{
	make_coe();

	int n, k;
	cin >> n >> k;

	if (k < 0 || k > n)
		cout << 0 << endl;
	else
		cout << coefficient[n][k] << endl;

	system("pause");

	return 0;
}