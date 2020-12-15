#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MAXNUM = 10001;

int v, e;
int parent[MAXNUM];

struct line_info
{
	int start;
	int goal;
	int value;
};

priority_queue<line_info> pq;
vector<line_info> res;

bool operator < (line_info t, line_info u)
{

	return t.value > u.value;
}


int FindParent(int num)
{
	if (num == parent[num])
		return num;
	else
	{
		parent[num] = FindParent(parent[num]);
		return parent[num];
	}
}

void Union(int n1, int n2)
{
	n1 = FindParent(n1);
	n2 = FindParent(n2);

	if (n1 != n2)
	{
		parent[n2] = n1;
	}
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}

	int a, b, c;

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		pq.push({ a, b,c });
	}
	
	while (!pq.empty())
	{
		line_info topInfo;
		topInfo = pq.top();
		pq.pop();

		if (FindParent(topInfo.start) != FindParent(topInfo.goal))
		{
			res.push_back({ topInfo.start,topInfo.goal,topInfo.value });
			Union(topInfo.start, topInfo.goal);
		}
		
		
	}
	
	int sum = 0;
	for (int i = 0; i < res.size(); i++)
	{
		sum += res[i].value;
	}

	cout << sum << endl;
	return 0;

}