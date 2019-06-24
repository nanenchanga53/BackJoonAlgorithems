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
	int left = -1;
	int right = -1;
	long long sum = 0;
};

deque<BinaryTree> tree;


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
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		depthNums *= 2;
	}

	for (int i = 1; i <= depthNums / 2; i++)
	{
		
	}


	system("pause");
	return 0;
}