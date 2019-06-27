#include<iostream>
using namespace std;
int self_num[10001] = { 0, };

void selfnum(int num)
{
	int tem, one, sum;

	sum = 0;
	one = num % 10;
	tem = num / 10;
	sum += one;

	while (tem > 0)
	{
		one = tem % 10;
		tem = tem / 10;
		sum += one;
	}

	if (num + sum < 10000)
	{
		self_num[num + sum] = 1;
		return selfnum(num + sum);
	}
}

int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		if (self_num[i] == 0)
			selfnum(i);
	}
	for (int i = 1; i < 10000; i++)
		if (self_num[i] == 0)
			cout << i << endl;

	return 0;
}