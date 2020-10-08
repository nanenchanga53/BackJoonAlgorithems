#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX_NUM 10001

using namespace std;

int nodeParent[MAX_NUM] = { 0,-1, };
vector<pair<int, int>> tree[MAX_NUM];
int farV=0,maxLen=0;
bool nodeSerch[MAX_NUM] = { false, };

void dfs(int root, int lenSum)
{
	if (nodeSerch[root] == true) return;
	nodeSerch[root] = true;
	for (int i = 0; i < tree[root].size(); i++)
	{
		
		int V = tree[root][i].first;
		int len = tree[root][i].second;

		if (nodeSerch[V] == true) continue;

		if (lenSum + len > maxLen)
		{
			farV = V;
			maxLen = lenSum + len;
		}
		dfs(V,lenSum + len);
		
	}

	if (nodeParent[root] != -1)
	{
		if (nodeSerch[nodeParent[root]] == false)
		{
			int len;

			for (int i = 0; i < tree[nodeParent[root]].size(); i++)
			{
				if (tree[nodeParent[root]][i].first == root)
				{
					len = tree[nodeParent[root]][i].second;
					break;
				}
			}

			if (lenSum + len > maxLen)
			{
				maxLen = lenSum + len;
			}
			dfs(nodeParent[root], lenSum + len);
		}
	}
}


int main()
{
	int n;
	cin >> n;
	int root, child, len;
	int far1, far2;
	for (int i = 0; i < n -1; i++)
	{
		cin >> root >> child >> len;
		tree[root].push_back({ child,len });
		nodeParent[child] = root;
	}

	farV = 0;
	maxLen = 0;
	fill(begin(nodeSerch),end(nodeSerch), false);

	dfs(1, 0);
	
	far1 = farV;
	maxLen = 0;
	fill(begin(nodeSerch), end(nodeSerch), false);
	dfs(far1, 0);
	far2 = farV;

	cout << maxLen;
	system("pause");
	return 0;
}