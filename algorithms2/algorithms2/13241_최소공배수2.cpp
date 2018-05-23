#include<iostream>
#include<algorithm>
using namespace std;

long long int GCD(long long int a, long long int b)
{
	long long int big, small;
	big = max(a, b);
	small = min(a, b);

	while (big != small)
	{
		int t;
		if (big % small == 0)
			big = small;
		else
			big = big % small;

		swap(big, small);
	}

	return big;
}

long long int LCM(long long int a,long long int b)
{
	return a * b / GCD(a, b);
}

int main()
{
	long long int a, b;
	
	cin >> a >> b;
	cout << LCM(a, b) << endl;
	
	system("pause");
	return 0;
}