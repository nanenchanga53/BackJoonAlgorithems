#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	long long gop;
	int k[10] = { 0, };
	cin >> a >> b >> c;
	gop = a * b * c;

	while (gop != 0)
	{
		k[gop % 10]++;
		gop /= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << k[i] << endl;


	return 0;

}