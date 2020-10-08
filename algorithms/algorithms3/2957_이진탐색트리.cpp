#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void fastscan(int &number);

int n, k;

map<int, long long> mapArr;


int InsertDepth(int x)
{
	int in;
	map<int, long long>::iterator lower_bound;
	map<int, long long>::iterator upper_bound;

	long long depth = 0;

	//key가 x인 요소의 이전, 다음 요소
	lower_bound = (--mapArr.lower_bound(x));
	upper_bound = (mapArr.upper_bound(x));
	depth = max(lower_bound->second, upper_bound->second) + 1;

	mapArr.insert(make_pair(x, depth));
	return depth;

}

int main()
{
	fastscan(n);

	int num;
	long long C = 0;

	mapArr.insert(make_pair(0, -1));
	mapArr.insert(make_pair(300001, -1));

	while (n--)
	{
		long long depth = 0;
		fastscan(num);
		depth = InsertDepth(num);

		C += depth;
		printf("%lld\n", C);
	}

	system("pause");
	return 0;
}

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
