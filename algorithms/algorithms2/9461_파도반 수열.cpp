#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long long> padoban;

int main()
{

	int T,k;
	int n;
	padoban.push_back(1);
	padoban.push_back(1);
	padoban.push_back(1);
	cin >> T;
	n = 3;
	while (T--)
	{
		cin >> k;
		if (k <= n)
			cout << padoban[k - 1] << endl;
		else
		{
			while (n < k)
			{
				n++;
				padoban.push_back(padoban[n-4]+padoban[n-3]);
			}
			cout << padoban.back() << endl;
		}
	}

	system("pause");
	return 0;
}