#include<iostream>
using namespace std;

int main()
{
	int n, sum, sun, mom;
	int i;

	cin >> n;
	i = 0;

	do
	{
		i++;
		n -= i;
	} while (n > 0);

	if (i % 2 == 1)
	{
		sun = abs(n) + 1;
		mom = i + n;
	}
	else
	{
		sun = i + n;
		mom = i - sun + 1;
	}

	cout << sun << "/" << mom << endl;

	system("pause");
	return 0;
}