#include<iostream>
using namespace std;
int main()
{
	int c, i, j;
	double score[1001];
	double sum, everage;


	cin >> c;
	for (i = 0; i < c; i++)
	{
		int n, cnt;
		cin >> n;
		sum = 0;
		for (j = 0; j < n; j++)
		{
			cin >> score[j];
			sum += score[j];
		}
		everage = sum / n;

		cnt = 0;
		for (j = 0; j < n; j++)
		{
			if (score[j] > everage)
				cnt++;
		}

		double res;

		cout << fixed;
		cout.precision(3);
		res = (double)cnt / n * 100.0;
		cout << res << '%' << endl;

	}

	return 0;
}