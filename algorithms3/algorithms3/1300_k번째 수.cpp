#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

void fastscan(int &number)
{
	//variable to indicate sign of input number
	bool negative = false;
	register int c;

	number = 0;

	// extract current character from buffer
	c = getchar();
	if (c == '-')
	{
		// number is negative
		negative = true;

		// extract the next character from the buffer
		c = getchar();
	}

	// Keep on extracting characters if they are integers
	// i.e ASCII Value lies from '0'(48) to '9' (57)
	for (; (c>47 && c<58); c = getchar())
		number = number * 10 + c - 48;

	// if scanned input has a negative sign, negate the
	// value of the input number
	if (negative)
		number *= -1;
}

int BinarySerch(int left, int right)
{
	if (left > right)
		return left;

	int mid = (left + right) / 2;
	int cnt = 0;

	//자신의 위치 까지의 배열값들을 세는 것
	// 1 2 3  4
	// 2 4 6  8
	// 3 6 9  12
	// 4 8 12 16
	// 이런식으로 있을테고 mid가 6이면 첫째줄은 6 / 1 하지만 n보다 크니 4 / 1개
	for (int i = 1; i <= n; i++)
	{
		cnt += n > (mid / i) ? (mid / i) : n;
	}
	
	if (cnt < k)
		return BinarySerch(mid + 1, right);
	else
		return BinarySerch(left, mid - 1);
	
}

int main()
{
	fastscan(n);
	fastscan(k);

	printf("%d ", BinarySerch(1,k));

	system("pause");
	return 0;
}
