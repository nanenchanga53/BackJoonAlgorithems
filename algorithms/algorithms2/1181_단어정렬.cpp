#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
using namespace std;

bool cmp(string a, string b)
{
	if (a.length() < b.length())
		return true;
	else if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] < b[i])
				return true;
			else if (a[i] > b[i])
				return false;
		}
		return false;
	}
	else
		return false;
}

int main()
{
	int n;
	string w;
	string words[20002];
	char word[51];
	cin >> n;
	cin.clear();

	for (int i = 0; i < n; i++)
	{
		cin >> word;
		words[i] = word;
	}

	sort(words, words + n, cmp);

	for (int i = 0; i < n; i++)
	{
		if (words[i] != words[i + 1])
			cout << words[i] << endl;
	}
	system("pause");
	return 0;
}