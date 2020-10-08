#include<iostream>
#include<algorithm>
#include<iomanip>
#define half 5000
int cnt = 0;
int i, j;
int big;
using namespace std;

int calc(int x,int y)
{
	int upperLeft;
	int lowerRight;
	if (x == 0 && y == 0)
		return 1;

	else if (x <= 0 && y <= 0 && x >= y || x >= y && y <= 0 && x + y <= 0)
	{
		upperLeft = (-2 * (y)+1)*(-2 * (y)+1) - (-y * 4);
		return upperLeft + (x - y);
	}
	else if (x <= 0 && y <= 0 && x <= y || x <= 0 && y >= 0 && x + y <= 0)
	{
		upperLeft = (-2 * (x)+1) * (-2 * (x)+1) - (-x * 4);
		return upperLeft + (x - y);
	}
	else if (x == y)
		return (2 * x + 1)*(2 * x + 1);
	else if (x <= y)
	{
		lowerRight = (2 * y - 1)*(2 * y - 1);
		return lowerRight - (x - y);
	}
	
	lowerRight = (2 * x + 1)*(2 * x + 1);
	return lowerRight + (y - x);

}

int main()
{
	int r1, c1, r2, c2;
	int digit;
	cin >> r1 >> c1 >> r2 >> c2;


	big = 0;
	big = max(calc(r1, c1), max(calc(r1, c2), max(calc(r2, c2), calc(r2, c1))));
	
	digit = 0;
	while (big != 0)
	{
		big /= 10;
		digit++;
	}
	
	for (i = r1; i <= r2; i++)
	{
		for (j = c1; j <= c2; j++)
			cout << setw(digit) << calc(i, j) << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}