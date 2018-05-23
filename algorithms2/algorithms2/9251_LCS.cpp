#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char word1[1001] = { 0, };
char word2[1001] = { 0, };
int LCS[1001][1001] = { 0, };
int main()
{
	int i, j;
	int len1;
	int len2;

	cin >> word1;
	cin >> word2;

	len1 = strlen(word1);
	len2 = strlen(word2);

	for(i=0;i<len1;i++)
		for (j = 0; j < len2; j++)
		{
			if (word1[i] == word2[j])
			{
				LCS[i + 1][j + 1] = LCS[i][j] + 1;
			}
			else
			{
				LCS[i + 1][j + 1] = max(LCS[i][j+1],LCS[i+1][j]);
			}
		}

	cout << LCS[len1][len2] << endl;

	system("pause");
	return 0;
}