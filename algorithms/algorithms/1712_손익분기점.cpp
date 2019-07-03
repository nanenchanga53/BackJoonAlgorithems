#include<iostream>
using namespace std;

int main()
{
	long long a=0, b=0, c=0;

	cin >> a >> b >> c;

	if (b >= c)
		cout << -1 << endl;
	else
	{
		cout << a / (c - b) + 1 << endl;
	}



	return 0;
}