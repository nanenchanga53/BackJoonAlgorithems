#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		int t;
		cin >> t;
		if (t < b)
			cout << t << endl;
	}
	return 0;
}