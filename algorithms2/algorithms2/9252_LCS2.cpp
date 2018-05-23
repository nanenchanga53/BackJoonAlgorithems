#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

char word1[1001] = { 0, };
char word2[1001] = { 0, };
int LCS[1001][1001] = { 0, };

vector<char> LCS_Word;

void BackTracking(int i,int j)
{
	if (i == 0 || j == 0)
		return;

	if (LCS[i][j] > LCS[i - 1][j - 1] && LCS[i][j] > LCS[i - 1][j] && LCS[i][j] > LCS[i][j - 1])
	{
		LCS_Word.push_back(word1[i - 1]);
		BackTracking(i - 1, j - 1);
	}
	else if (LCS[i][j] > LCS[i - 1][j] && LCS[i][j] == LCS[i][j - 1])
		BackTracking(i, j - 1);
	else
		BackTracking(i - 1, j);
	
}

int main()
{
	int i, j;
	int len1;
	int len2;

	cin >> word1;
	cin >> word2;

	len1 = strlen(word1);
	len2 = strlen(word2);

	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			if (word1[i] == word2[j])
			{
				LCS[i + 1][j + 1] = LCS[i][j] + 1;
			}
			else
			{
				LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
			}
		}
	}

	BackTracking(len1,len2);

	cout << LCS[len1][len2] << endl;
	for (i = LCS_Word.size() - 1; i >= 0; i--)
	{
		cout << LCS_Word[i];
	}
	cout << endl;

	system("pause");
	return 0;
}