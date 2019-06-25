#include<iostream>
using namespace std;
int main()
{
	int year;
	cin >> year;
	bool young = false;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		young = true;
	}
	else
	{
		young = false;
	}


	cout << (young ? 1 : 0) << endl;

	return 0;
}