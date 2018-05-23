#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int m, n, time, mCnt;

vector<int> mentionCnt;

int mention[27][27] = { 0, };
int pointX[5] = { -1,0,1,0 };
int pointY[5] = { 0,-1,0,1 };
bool flag[27][27] = { 0, };

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if((mention[x + pointX[i]][y + pointY[i]] == 1) && (flag[x + pointX[i]][y + pointY[i]] == false))
		{
			flag[x + pointX[i]][y + pointY[i]] = true;
			mention[x + pointX[i]][y + pointY[i]] = time;
			dfs(x + pointX[i], y + pointY[i]);
			mCnt++;
		}
	}
}

int main()
{
	int x, y;
	time = 1;
	mCnt = 0;
	cin >> n;
	cin.get();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mention[i][j] = cin.get() - '0';
		}
		cin.get();
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (mention[i][j] == 1 && flag[i][j] == false)
			{
				mCnt = 1;
				mention[i][j] = time;
				flag[i][j] = true;
				dfs(i, j);
				mentionCnt.push_back(mCnt);
				time++;
			}
		}
	}
	
	sort(mentionCnt.begin(), mentionCnt.end());

	cout << time - 1 << endl;
	for (int i = 0; i < mentionCnt.size(); i++)
	{
		cout << mentionCnt[i] << endl;
	}
	system("pause");
	return 0;
}
