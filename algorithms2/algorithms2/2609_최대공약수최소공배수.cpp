#include<iostream>
#include<algorithm>
using namespace std;

int GCD(int a, int b)
{
	int big, small;
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

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int main()
{
	int a, b;
		cin >> a >> b;
		cout << GCD(a, b) << endl;
		cout << LCM(a, b) << endl;
	system("pause");
	return 0;
}