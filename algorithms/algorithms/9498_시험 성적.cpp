#include<iostream>
using namespace std;
int main()
{
	int i, n;
	cin >> n;

	if (n >= 90)
		cout << 'A' << endl;
	else if (n >= 80 && n < 90)
		cout << 'B' << endl;
	else if (n >= 70 && n < 80)
		cout << 'C' << endl;
	else if (n >= 60 && n < 70)
		cout << 'D' << endl;
	else
		cout << 'F' << endl;

}