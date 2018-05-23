#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int n, m;
	int i, cnt = 0, check = 0;
	bool people[1001];
	memset(people, true, sizeof(people));

	cin >> n >> m;
	i = 0;

	cout << "<";
	while (cnt < n)
	{
		check = 0;
		while (check < m)
		{
			if (people[++i])
			{
				check++;
			}

			if (i == n)
				i = 0;
		}

		if (i == 0)
		{
			cout << n;
			if (cnt < n - 1)
			{
				cout << ",";
				cout << " ";
			}
			people[n] = false;
		}
		else
		{
			cout << i;
			if (cnt < n - 1)
			{
				cout << ",";
				cout << " ";
			}
			people[i] = false;
		}

		cnt++;
	}

	cout << ">" << endl;

	return 0;
}