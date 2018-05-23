#include<iostream>
using namespace std;

int count_2, count_5;

void counting(int num)
{
	int cnt_2, cnt_5;
	cnt_2 = cnt_5 = 0;

	while (num % 2 == 0)
	{
		cnt_2++;
		num /= 2;
	}

	while (num % 5 == 0)
	{
		cnt_5++;
		num /= 5;
	}

	count_2 += cnt_2;
	count_5 += cnt_5;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int n;
	count_2 = count_5 = 0;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		counting(i);
	}

	int min_num = min(count_2, count_5);
	cout << min_num << endl;
	system("pause");
	return 0;
}