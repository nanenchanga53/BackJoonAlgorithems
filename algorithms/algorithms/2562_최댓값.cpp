#include<iostream>
using namespace std;
int main()
{
	int n = 9;
	int big = 0, orderd = 0;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		if (big < num)
		{
			big = num;
			orderd = i;
		}
	}
	cout << big << endl;
	cout << orderd << endl;
	return 0;
}