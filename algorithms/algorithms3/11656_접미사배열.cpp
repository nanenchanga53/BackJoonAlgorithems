#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

vector<pair<string, int>> SuffixArray;

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

	string S;

	int SLen = 0;

	getline(cin, S);

	SLen = S.size();

	for (int i = 0; i < SLen; i++)
	{
		SuffixArray.push_back(make_pair(S.substr(i, SLen - i), i + 1));
	}

	sort(SuffixArray.begin(), SuffixArray.end());

	for (int i = 0; i < SLen; i++)
	{
		int maxNum = 0;
		cout << SuffixArray[i].first << endl;
	}


	system("pause");
	return 0;
}