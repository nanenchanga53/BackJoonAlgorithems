#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char t[101];
	int alpa[28] = { 0, };
	cin.getline(t, 100);

	for (int i = 0; i < 26; i++)
		alpa[i] = -1;

	int len = strlen(t);

	for (int i = 0; i < len; i++)
	{
		if (alpa[t[i] - 'a'] == -1)
			alpa[t[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alpa[i];
		if (i < 25)
			cout << " ";
	}
	return 0;
}