#include<iostream>
using namespace std;
int main()
{
	int a;
	int bag[5001];
	cin >> a;

	for (int i = 1; i <= 5000; i++)
		bag[i] = -1;
	bag[3] = 1;
	bag[5] = 1;

	for (int i = 6; i <= 5000; i++)
	{
		if (bag[i - 3] != -1)
			bag[i] = bag[i - 3] + 1;

		if (bag[i - 5] != -1 && i > 5)
		{
			if (bag[i] != -1 && bag[i] < bag[i - 5])
				bag[i] = bag[i];
			else
				bag[i] = bag[i - 5] + 1;
		}

	}

	cout << bag[a] << endl;
	return 0;
}