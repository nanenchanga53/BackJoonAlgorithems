#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<string>
using namespace std;

char * dat;
int n;

bool check_same(int x,int y,int len)
{
	char * du;
	char p;
	int start = x * n + y;
	
	if (len == 1)
		return 1;

	du = (char *)malloc(sizeof(char) * len+1);
	strncpy_s(du,sizeof(char) * len + 1, dat + start, len);
	p = du[0];
	for (int i = 1; i < len; i++)
	{
		if (du[i] != p)
			return 0;
	}
	for (int i = 1; i < len; i++)
	{
		if (strncmp(dat + start + (i*n), du , len))
		{
			return 0;
		}
	}
	return 1;
}

char qurd_tree(int x,int y,int len)
{
	char q1, q2, q3, q4;
	q1 = q2 = q3 = q4 = NULL;
	if(check_same(x, y, len))
	{
		
		int start = x * n + y;
		char t = dat[start];

		return t;
	}
	else
	{
		cout << '(';
		
		q1 = qurd_tree(x, y, len / 2);
		if(q1 != NULL)
			cout << q1;
		
		q2 = qurd_tree(x, y + len / 2, len / 2);
		if(q2 != NULL)
			cout << q2;

		q3 = qurd_tree(x + len / 2, y, len / 2);
		if(q3 != NULL)
			cout << q3;
		
		q4 = qurd_tree(x + len / 2, y + len / 2, len / 2);
		
		if(q4 != NULL)
			cout << q4;
		cout << ')';
	}
	return NULL;
	
}

int main()
{
	

	cin >> n;
	cin.ignore();
	dat = (char *)malloc(sizeof(char)*n*n + 1);

	for (int i = 0; i < n; i++)
	{
		cin.getline(dat + (i * n), n + 1);
	}
	dat[n*n] = NULL;

	if (check_same(0,0,n))
		cout << dat[0];
	else
		qurd_tree(0,0,n);

	system("pause");
	return 0;
}