#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N;
int status[21][21] = { 0, };
int similerNum = 1e6;


void MakeTeam(vector<int>& start,vector<int>& link)
{
	if (link.size() == N / 2)
	{
		int startStat = 0;
		int linkStat = 0;

		for (int i = 0; i < link.size() - 1; i++)
		{
			for (int j = i+1; j < link.size(); j++)
			{
				startStat += status[start[i]][start[j]];
				startStat += status[start[j]][start[i]];

				linkStat += status[link[i]][link[j]];
				linkStat += status[link[j]][link[i]];
			}

		}

		if (abs(startStat - linkStat) < similerNum)
		{
			similerNum = abs(startStat - linkStat);
		}

	}
	else
	{
		for (int i = 0; i < link.size(); i++)
		{
			int startS = link[i];
			if ((start.empty() ? -1 : start.back()) < startS)
			{
				start.push_back(startS);
				link.erase(link.begin() + i);
				MakeTeam(start, link);
				link.insert(link.begin() + i, startS);
				start.pop_back();
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	vector<int> start;
	vector<int> link;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		link.push_back(i);
		for (int j = 0; j < N; j++)
		{
			cin >> status[i][j];
		}
	}
	
	MakeTeam(start,link);

	cout << similerNum;
	return 0;
}