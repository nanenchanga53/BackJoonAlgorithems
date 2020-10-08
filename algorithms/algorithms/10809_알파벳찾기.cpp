#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char word[101];
	int alpa[28] = { 0, };
	cin >> word;
	cin.clear();

	/*string word;
	getline(cin, word);
	cin.clear();*/

	memset(alpa, -1, sizeof(alpa));

	int len = strlen(word);

	for (int i = 0; i < len; i++)
	{
		if (alpa[word[i] - 'a'] == -1)
			alpa[word[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alpa[i];
		if (i < 25)
			cout << " ";
	}
	cout << endl;
	return 0;
}