#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
	int check_al[27] = { 0, };

	int n, len, i;
	char word[101];
	bool flag;
	int cnt = 0;
	cin >> n;
	len = 0;
	for (int N = 0; N < n; N++)
	{
		cin >> word;
		len = strlen(word);
		flag = false;
		memset(check_al, 0, sizeof(check_al));
		check_al[word[0] - 'a'] = 1;

		for (i = 1; i < len; i++)
		{
			if (word[i] != word[i - 1])
			{
				if (check_al[word[i] - 'a'] == 0)
				{
					check_al[word[i] - 'a'] = 1;
				}
				else
					break;
				flag = true;
			}
			else
				flag = false;
		}
		if (i == len)
		{
			cnt++;
		}
	}
	cout << cnt << endl;

	system("pause");
	return 0;
}