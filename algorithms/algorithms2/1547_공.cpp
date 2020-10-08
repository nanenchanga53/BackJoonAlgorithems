#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int m,x,y;
	int cup[4] = { 0,1,0,0 };
	cin >> m;
	while (m--)
	{
		cin >> x >> y;
		swap(cup[x], cup[y]);
	}
	for (int i = 1; i <= 3; i++)
	{
		if (cup[i] == 1)
		{
			cout << i << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
