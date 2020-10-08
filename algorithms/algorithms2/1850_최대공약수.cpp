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
	int a, b;
	cin >> a >> b;



	for (int i = 0; i < GCD(a, b); i++)
		cout << '1';
	cout << endl;
	system("pause");
	return 0;
}