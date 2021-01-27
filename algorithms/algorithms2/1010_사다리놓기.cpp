#include<iostream>
using namespace std;

int T;
int n,m;
long long pas[31][31];

void PascalTriangle()
{
	pas[0][0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		pas[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}
	
}
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> T;
	PascalTriangle();

	while (T--)
	{
		cin >> n >> m;

		cout << pas[m][n] << '\n';
	}
		
	return 0;

}