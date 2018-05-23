#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long i, n;

	long long pibo[91] = { 0,1,1, };

	for (int i = 3; i <= 90; i++)
		pibo[i] = pibo[i - 1] + pibo[i - 2];

	cin >> n;

	cout << pibo[n] << endl;

	system("pause");
	return 0;
}