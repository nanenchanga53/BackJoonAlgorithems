#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX_SIZE 100001
using namespace std;

int nodeParent[MAX_SIZE] = { 0 };
vector<int> connectedNode[MAX_SIZE];
int total_node;

void bfs()
{
	queue<pair<int, int>> bfsQueue;

	for (int i = 0; i < connectedNode[1].size(); i++)
	{
		bfsQueue.push({ 1,connectedNode[1].at(i) });
	}

	while (bfsQueue.size())
	{
		pair<int, int> subConnect = bfsQueue.front();
		bfsQueue.pop();

		nodeParent[subConnect.second] = subConnect.first;

		for (int i = 0; i < connectedNode[subConnect.second].size(); i++)
		{
			if (nodeParent[connectedNode[subConnect.second].at(i)] == 0)
			{
				bfsQueue.push({ subConnect.second, connectedNode[subConnect.second].at(i) });
			}
		}

	}

}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int subNode1, subNode2;
		cin >> subNode1 >> subNode2;
		connectedNode[subNode1].push_back(subNode2);
		connectedNode[subNode2].push_back(subNode1);
	}

	nodeParent[1] = -1;
	bfs();

	for (int i = 2; i <= n; i++)
	{
		cout << nodeParent[i] << endl;
	}

	system("pause");
	return 0;
}