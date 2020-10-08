#include<iostream>
#include<algorithm>
using namespace std;

long long lens[1000001];

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

void fastscan(long long &number)
{
	//variable to indicate sign of input number
	bool negative = false;
	register long long c;

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k, n;
	fastscan(k);
	fastscan(n);

	long long left, mid, right;
	left = 1;
	right = 0;
	for (int i = 0; i < k; i++)
	{
		fastscan(lens[i]);
		right = max(right, lens[i]);
	}

	long long ans;
	while (left <= right)
	{
		int d = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < k; i++)
		{
			 d += lens[i] / mid;
		}

		if (d >= n)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans << endl;

	system("pause");
	return 0;
}

