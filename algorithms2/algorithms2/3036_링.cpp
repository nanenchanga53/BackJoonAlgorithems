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
int main()
{
	int t;
	int a, b,n;
	int GC;
	cin >> t;
	cin >> n;
	int num;
	for (int i = 0; i < t - 1; i++)
	{
		cin >> num;
		GC = GCD(n, num);
		cout << n / GC << "/" << num / GC << endl;
	}
	
	system("pause");
	return 0;
}