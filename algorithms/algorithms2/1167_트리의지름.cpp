#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_NUM 100001
using namespace std;

vector<pair<int, int>> treeLength[MAX_NUM];
int farV,maxLength,maxV;

int dfs(int v1,int lengthSum,int lastV)
{
	int linkV, length;
	for (int i = 0; i < treeLength[v1].size(); i++)
	{
		linkV = treeLength[v1][i].first;
		length = treeLength[v1][i].second;
		if (linkV == lastV) continue;

		if (lengthSum + length > maxLength)
		{
			maxLength = lengthSum + length;
			maxV = linkV;
		}
		dfs(linkV,lengthSum + length,v1);
	}
	return maxV;
}

int main()
{
	int V;
	cin >> V;

	for (int i = 0; i < V; i++)
	{
		int v1, v2, length;
		cin >> v1;
		while (1)
		{
			cin >> v2;
			if (v2 == -1) break;
			cin >> length; 
			treeLength[v1].push_back({ v2,length });

		}
	}

	maxLength = 0;
	maxV = 0;
	dfs(1,0,-1);
	maxLength = 0;
	dfs(maxV, 0, -1);

	cout << maxLength;

	system("pause");
	return 0;
}