#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_NUM 5000001

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
	int n,k;
	n = readInt();
	k = readInt();


	for (int i = 0; i < n; i++)
	{
		num[i] = readInt();
	}

	sort(num, num + n);

	cout << num[k-1] << endl;

	system("pause");

	return 0;
}