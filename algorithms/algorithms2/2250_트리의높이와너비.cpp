#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX_NUM 10001

using namespace std;

vector<pair<int, int>> tree[MAX_NUM];
vector<int> treesLV[MAX_NUM];
bool NrootNode[MAX_NUM] = { false, };
int pt=0;

void inOrder(int root,int lv)
{
	int left = tree[root].front().first;
	int right = tree[root].front().second;


	if (left != -1) inOrder(left, lv + 1);
	//·¹º§
	treesLV[lv].push_back(++pt);
	if (right != -1) inOrder(right, lv + 1);
}


int main()
{
	int n;
	cin >> n;
	int root, left, right;

	for (int i = 0; i < n; i++)
	{
		cin >> root >> left >> right;
		tree[root].push_back(make_pair(left, right));
		if (left != -1) NrootNode[left] = true;
		if (right != -1) NrootNode[right] = true;
	}

	for (root = 1; root <= n; root++)
		if (NrootNode[root] == false) break;

	
	inOrder(root, 1);

	int Blength=0;
	int Blv=0;
	for (int i = 1;!treesLV[i].empty(); i++)
	{
		int treesize = treesLV[i].size();
		if (treesLV[i][treesize - 1] - treesLV[i][0] + 1 > Blength)
		{
			Blength = treesLV[i][treesize - 1] - treesLV[i][0] + 1;
			Blv = i;

		}
	}

	cout << Blv << " " << Blength;

	system("pause");
	return 0;
}