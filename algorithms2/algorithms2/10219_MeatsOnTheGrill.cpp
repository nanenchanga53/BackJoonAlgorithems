#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	int h, w;

	char meat[11][11];
	cin >> t;
	
	while (t--)
	{
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			cin >> meat[i];

		for (int i = 0; i < h; i++)
		{
			for (int j = w-1; j >= 0 ; j--)
			{
				cout << meat[i][j];
			}
			cout << endl;
		}

		system("pause");
	}
}