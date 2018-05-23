#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char num[1000001];
	int use[11] = { 0 };

	cin >> num;

	int len = strlen(num);

	for (int i = 0; i < len; i++)
	{
		if (num[i] == '9')
			num[i] = '6';
		use[num[i] - '0']++;
	}
	if (use[6] % 2 == 1)
		use[6]++;
	use[6] /= 2;

	int big = 0;

	for (int i = 0; i <= 8; i++)
		if (big < use[i])
			big = use[i];

	cout << big << endl;

	system("pause");
	return 0;
}