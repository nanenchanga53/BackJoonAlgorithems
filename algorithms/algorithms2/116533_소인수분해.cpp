#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	int divNum=2;

	while (n % divNum == 0 && n > 1)
	{
		n /= divNum ;
		cout << 2 << '\n';
	}


	for (divNum = 3; divNum <= n; divNum += 2)
	{
		while (n % divNum == 0 && n > 1)
		{
			n /= divNum;
			cout << divNum << '\n';
		}
	}
	
	return 0;
}