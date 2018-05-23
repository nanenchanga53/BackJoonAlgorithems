#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int i, j;
	int f;
	int coin;
	char yu;
	for (int t = 3; t > 0; t--)
	{
		f = 0;
		for (i = 0; i < 4; i++)
		{
			cin >> coin;
			if (coin == 0)
				f++;
		}
		switch (f)
		{
		case 1:
			yu = 'A';
			break;
		case 2:
			yu = 'B';
			break;
		case 3:
			yu = 'C';
			break;
		case 4:
			yu = 'D';
			break;
		case 0:
			yu = 'E';
			break;
		default:
			break;
		}
		cout << yu << endl;
	}


	system("pause");
	return 0;
}