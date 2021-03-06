#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;




vector<int> getPi(string p)
{
	int m = p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
		{
			j = pi[j - 1];
		}
		if (p[i] == p[j])
		{
			pi[i] = ++j;
		}
	}
	return pi;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string t;

	while (1)
	{
		getline(cin, t);
		if (t == ".")
			break;

		auto pies = getPi(t);

		for (int i = t.size(); i > 0; i--)
		{
			if (pies[t.size() - 1] == (double)((double)(i - 1) / i) * (double)t.size())
			{
				cout << i << endl;
				break;
			}
		}
	}

	
	system("pause");
	return 0;
}