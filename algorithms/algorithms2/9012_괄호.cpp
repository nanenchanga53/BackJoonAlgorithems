#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int left, right;

	int T;
	int len;
	char ps[51];

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> ps;
		len = strlen(ps);
		left = right = 0;
		for (int i = 0; i < len; i++)
		{
			if (ps[i] == '(')
			{
				left++;
			}
			else if (ps[i] == ')')
			{
				right++;
			}

			if (right > left)
				break;
		}

		if (left == right)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}

	return 0;
}