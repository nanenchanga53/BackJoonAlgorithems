#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	/*
	char k;
	int cnt=1;
	while((k = getchar()) != '\n' && k != EOF)
	{
		if(k == ' ')
			cnt++;
	}
	cout << cnt << endl;
	*/
	char k[1000001];

	cin.getline(k, 1000000);
	cin.clear();

	int len, cnt;
	bool flag = false;
	len = strlen(k);
	if (len == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	cnt = 0;
	for (int i = 0; i < len; i++)
		if (flag == false && k[i] != ' ')
		{
			cnt++;
			flag = true;
		}
		else if (flag == true && k[i] == ' ')
			flag = false;


	cout << cnt << endl;

	return 0;
}