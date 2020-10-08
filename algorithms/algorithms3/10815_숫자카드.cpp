#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int n, m;

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


int main()
{
	fastscan(n);
	for (int i = 0; i < n; i++)
	{
		fastscan(arr[i]);
	}

	fastscan(m);

	sort(arr, arr + n);

	int exsitNum = 0, lastNum = 0;


	for (int i = 0; i < m; i++)
	{
		fastscan(exsitNum);

		printf("%d ",(binary_search(arr,arr+n,exsitNum) ? 1 : 0));
	}

	system("pause");
	return 0;
}
