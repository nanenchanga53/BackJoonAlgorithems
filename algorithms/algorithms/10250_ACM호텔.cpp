#include<iostream>
using namespace std;
int main()
{
	int T, i;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int h, w, n;
		cin >> h;
		cin >> w;
		cin >> n;

		int res = 0, qes = 1;
		while (n > 0)
		{
			if (res == h)
			{
				res = 0;
				qes++;
			}
			res++;
			n--;
		}

		int done;

		done = res * 100 + qes;
		cout << done << endl;
	}
	system("pause");
	return 0;
}