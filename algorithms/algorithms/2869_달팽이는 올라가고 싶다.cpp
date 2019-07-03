#include<iostream>
using namespace std;

int main()
{
	long long a = 0, b = 0, v = 0;

	cin >> a >> b >> v;
	
	if ((v - a) % (a - b) == 0)
		cout << (v - a) / (a - b) + 1 << endl;
	else
		cout << (v - a) / (a - b) + 2 << endl;

	return 0;
}