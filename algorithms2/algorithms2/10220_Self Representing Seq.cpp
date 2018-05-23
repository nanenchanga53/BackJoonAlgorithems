#include <iostream>
#include <cstring>
using namespace std;
//https://en.wikipedia.org/wiki/Self-descriptive_number
int main()
{
	
	int T;
	cin >> T;
	int a[101];
	for (int i = 1; i <= 100; i++)
		a[i] = 1;
	a[1] = a[2] = a[3] = a[6] = 0;
	a[4] = 2;

	int t;
	while(T--)
	{
		cin >> t;
		cout << a[t] << endl;
	}

	system("pause");
	return 0;
}