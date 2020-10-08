#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;
#define MAXNUM 1000001

int k;

struct BinaryTree
{
	int left = -1;
	int right = -1;
};

BinaryTree tree[MAXNUM];

void postOrder(int node)
{
	if (tree[node].left != -1)
	{
		postOrder(tree[node].left);
	}

	if (tree[node].right != -1)
	{
		postOrder(tree[node].right);
	}
	printf("%d\n", node);
}


int main()
{
	FILE *inputFile;
	inputFile = new FILE;
	freopen_s(&inputFile,"input.txt", "r", stdin);

	int root;
	int value;
	scanf_s("%d", &root);
	while(scanf_s("%d", &value) != EOF)
	{
		int node = root;
		while (1)
		{
			if (node < value)
			{
				if (tree[node].right != -1)
				{
					node = tree[node].right;
				}
				else
				{
					tree[node].right = value;
					break;
				}
			}
			else
			{
				if (tree[node].left != -1)
				{
					node = tree[node].left;
				}
				else
				{
					tree[node].left = value;
					break;
				}
			}
		}

	}


	postOrder(root);

	fclose(stdin);
	system("pause");
	
	return 0;
}