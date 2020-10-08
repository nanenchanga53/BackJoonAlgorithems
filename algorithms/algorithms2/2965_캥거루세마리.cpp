#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int kan[4] = { 0, };
	int cnt = 0;
	cin >> kan[1] >> kan[2] >> kan[3];
	
	while (1)
	{
		if (kan[1] + 1 == kan[2] && kan[2] + 1 == kan[3])
			break;

		if (kan[2] - kan[1] < kan[3] - kan[2])
		{
			kan[1] = kan[2];
			kan[2] = kan[2] + 1;
		}
		else
		{
			kan[3] = kan[2];
			kan[2] = kan[2] - 1;
		}
		cnt++;

	}

	cout << cnt << endl;
	system("pause");
	return 0;
}