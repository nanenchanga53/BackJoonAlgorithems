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
		if (big % small == 0)
			big = small;
		else
			big = big % small;

		swap(big, small);
	}

	return big;
}

int main() {
	int t;
	int a, b, c;
	int gcd;
	cin >> t;

	while (t--)
	{
		cin >> a >> b;
		
		while (a > 0)
		{
			if (a > 1)
				c = b / a + 1;
			else
			{
				c = b / a;
				break;
			}
			a = (a * c) - b;
			b = b * c;
			gcd = GCD(a, b);
			a /= gcd;
			b /= gcd;
		}
		cout << c << endl;
	}

	system("pause");
	return 0;
}