#include<iostream>
using namespace std;
int equalsNum(int a, int b, int c)
{
	return (a == b ? c : (b == c ? a : b));
}

int main()
{
	int x[4];
	int y[4];

	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}
	cout << equalsNum(x[0], x[1], x[2]) << ' ' << equalsNum(y[0], y[1], y[2]) << endl;
	return 0;
}