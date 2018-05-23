#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int one_time[1000001] = { 0, };

void make_one(int n)
{
	int min = n;
	if (n % 2 == 0)
	{
		min = n / 2;
	}

	if (n % 3 == 0)
	{
		if (one_time[min] > one_time[min / 3])
			min = n / 3;
	}

	if (one_time[n - 1] < one_time[min])
	{
		min = n - 1;
	}

	one_time[n] = one_time[min] + 1;
}

int main()
{
	int n;
	cin >> n;
	memset(one_time, 1000000, sizeof(int) * 1000000);
	one_time[1] = 0;
	one_time[2] = one_time[3] = 1;

	for (int i = 4; i <= 1000000; i++)
		make_one(i);

	cout << one_time[n] << endl;
	system("pause");
	return 0;
}