#include<iostream>
using namespace std;
int main()
{
	int T1, T2;
	cin >> T1 >> T2;
	cout << T1 * (T2 % 10) << endl;
	cout << T1 * ((T2 / 10) % 10)  << endl;
	cout << T1 * (T2 / 100) << endl;
	cout << T1 * T2 << endl;


	return 0;
}