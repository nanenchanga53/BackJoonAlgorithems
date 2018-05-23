#include<iostream>
#include<cstring>
using namespace std;

// 'c=' 'c-' 'dz=' 'd-' 'lj' 'nj' 's=' 'z='

int main()
{
	int i, j;
	int len;
	int croatia;
	char text[101];

	cin >> text;

	len = strlen(text);
	croatia = len;

	for (i = 0; i < len; i++)
	{
		if (text[i] == '=')
		{
			if (text[i - 1] == 'z')
			{
				if (text[i - 2] == 'd')
					croatia--;
				croatia--;
			}
			else if (text[i - 1] == 's')
				croatia--;
			else if (text[i - 1] == 'c')
				croatia--;
		}
		else if (text[i] == '-')
		{
			if (text[i - 1] == 'd')
				croatia--;
			else if (text[i - 1] == 'c')
				croatia--;
		}
		else if (text[i] == 'j')
		{
			if (text[i - 1] == 'l')
				croatia--;
			else if (text[i - 1] == 'n')
				croatia--;
		}
	}

	cout << croatia << endl;
	system("pause");
	return 0;
}