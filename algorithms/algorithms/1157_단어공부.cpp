#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
	int len;
	int big;
	char big_char;
	bool check;
	int al[28] = { 0, };
	char st[1000001];

	big = 0;
	cin >> st;
	check = false;
	len = strlen(st);

	for (int i = 0; i < len; i++)
	{
		int t;
		if (st[i] >= 'a' && st[i] <= 'z')
			t = st[i] - 'a';
		else if (st[i] >= 'A' && st[i] <= 'Z')
			t = st[i] - 'A';

		al[t]++;
		if (al[t] > big)
		{
			big = al[t];
			big_char = st[i];
			check = false;
		}
		else if (al[t] == big)
		{
			check = true;
		}
	}
	big_char = toupper(big_char);
	if (check == true)
		cout << '?' << endl;
	else
		cout << big_char << endl;
	system("pause");
	return 0;
}