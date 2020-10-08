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
	int largest = 0;

	string T;
	getline(cin, T);

	for (int i = 0; i < T.size(); i++)
	{
		string stringPice = "";

		stringPice = T.substr(i, T.size() - i);
		auto pies = getPi(stringPice);

		for (auto length : pies)
		{
			largest = max(length, largest);
		}
	}
	cout << largest << endl;

	system("pause");
	return 0;
}