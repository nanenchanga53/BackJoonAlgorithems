#include<iostream>
using namespace std;

#define MAX_NUM 10001

int num[MAX_NUM] = { 0, };

int readInt()
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch - '0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main()
{
	int t;
	int n;
	n = readInt();

	for (int i = 0; i < n; i++)
	{
		t = readInt();
		num[t]++;
	}

	for (int i = 1; i < MAX_NUM; i++)
	{
		for (int j = 0; j < num[i]; j++)
			printf("%d\n", i);
	}

	system("pause");

	return 0;
}