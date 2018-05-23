#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int i, j;
		int r;
		int len;
		char text[21];
		char new_text[161];
		cin >> r;
		cin >> text;

		len = strlen(text);

		for (i = 0; i < len; i++)
		{
			for (j = 0; j < r; j++)
			{
				new_text[i*r + j] = text[i];
			}
			new_text[i*r + j] = NULL;
		}

		cout << new_text << endl;
	}
	return 0;
}