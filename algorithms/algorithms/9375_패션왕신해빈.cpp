#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	int T;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		map<string, int> m;
		map<string, int>::iterator i;
		int n;
		char wearType[21];
		char cloat[21];

		cin >> n;
		for (; n > 0; n--)
		{
			cin >> cloat >> wearType;
			m[wearType]++;
		}

		int ans = 1;

		for (i = m.begin(); i != m.end(); i++)
		{
			ans *= (i->second + 1);
		}
		ans--;
		cout << ans << endl;
	}
	system("pause");
	return 0;
}