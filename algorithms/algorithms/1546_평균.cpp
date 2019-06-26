#include<iostream>
using namespace std;
int main()
{
	int n;
	double score[10001];
	double big;
	big = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
		if (big < score[i])
			big = score[i];
	}

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += score[i] / big * 100;
	}
	cout << fixed;
	cout.precision(2);

	cout << sum / (double)n << endl;
	return 0;
}