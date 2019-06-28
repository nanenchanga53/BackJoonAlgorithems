#include<iostream>
using namespace std;
int main()
{
	int i, j, n, m, cnt;
	cin >> n >> m;
	cnt = i = j = 1;

	while (1)
	{
		if (i == n && j == m)
			break;
		if (i == 2 && j == 28)
		{
			i++;
			j = 1;
		}
		else if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) && j == 31)
		{
			i++;
			j = 1;
		}
		else if ((i == 4 || i == 6 || i == 9 || i == 11) && j == 30)
		{
			i++;
			j = 1;
		}
		else
			j++;
		cnt++;
	}

	cnt = cnt % 7;

	if (cnt == 1)
		cout << "MON" << endl;
	else if (cnt == 2)
		cout << "TUE" << endl;
	else if (cnt == 3)
		cout << "WED" << endl;
	else if (cnt == 4)
		cout << "THU" << endl;
	else if (cnt == 5)
		cout << "FRI" << endl;
	else if (cnt == 6)
		cout << "SAT" << endl;
	else if (cnt == 0)
		cout << "SUN" << endl;
	//SUN, MON, TUE, WED, THU, FRI, SAT
	return 0;

}