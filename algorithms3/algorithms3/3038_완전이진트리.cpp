#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define MAXNUM 32770

int N;

struct BinaryTree
{
	int num;
	long long sum = 0;
};

deque<BinaryTree> tree;
queue<int> qu;

void postOrder(int node)
{
	/*printf("%d\n", node);

	if (tree[node].left != -1)
	{
		postOrder(tree[node].left);
	}

	if (tree[node].right != -1)
	{
		postOrder(tree[node].right);
	}*/
	
}

int main()
{
	int N, depthNums = 1;
	bool flag[MAXNUM] = { 0, };
	bool time = false;
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		depthNums *= 2;
	}

	tree.push_back({0,0});

	for (int i = 1; i <= depthNums / 2; i++)
	{
		tree.push_back({ i,(long long)i });
		qu.push(i);
		flag[i] = true;
		tree.push_back({ i + depthNums / 2, (long long)(i + depthNums / 2) });
		flag[i + depthNums / 2] = true;
	}
	
	int lastfront = 1;
	int firstNum = 1;
	int bigNum = depthNums * 2;
	while (!qu.empty())
	{
		firstNum *= 2;
		depthNums /= 2;
		int lastSum = 0;
		deque<BinaryTree>::iterator iter = tree.begin() + firstNum;
		for (int i = 1; i <= depthNums; i++, iter += (((i - 1) * depthNums) + 1))
		{
			deque<BinaryTree>::iterator leftNode = iter - 1;
			BinaryTree nodeInfo;
			nodeInfo = *iter;
			nodeInfo.num += (*leftNode).sum;

			if (i % 2 == 1)
			{
				nodeInfo.num = bigNum;
				flag[bigNum] = true;
				lastSum = nodeInfo.sum;
			}
			else
			{
				nodeInfo.num = lastSum - nodeInfo.sum;
				bigNum - 1;
			}

			tree.insert(iter, nodeInfo);

		}
	
	}

	system("pause");
	return 0;
}