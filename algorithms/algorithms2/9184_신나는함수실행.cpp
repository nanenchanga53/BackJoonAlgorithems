//if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
//1
//
//if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
//w(20, 20, 20)
//
//if a < band b < c, then w(a, b, c) returns :
//	w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
//
//	otherwise it returns :
//w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)

#include<iostream>
using namespace std;

int dp[51][51][51];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	int& resualt = dp[a][b][c];

	if (resualt != 0) 
		return resualt;

	else if (a > 20 || b > 20 || c > 20)
		return resualt = w(20, 20, 20);

	else if (a < b && b < c)
		return resualt = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	else 
		return resualt = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int a, b, c;
	int n;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		n = w(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, n);
	}

	return 0;

}