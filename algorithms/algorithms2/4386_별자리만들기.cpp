#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXNUM = 101;

int n;
int parent[MAXNUM];
pair<double, double> points[MAXNUM];

struct line_info
{
	int start;
	int goal;
	double value()
	{
		return sqrt(pow((points[start].first - points[goal].first),2) + pow((points[start].second - points[goal].second),2));
	}

};

priority_queue<line_info> pq;
vector<line_info> res;

bool operator < (line_info t, line_info u)
{

	return t.value() > u.value();
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

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	double x, y;

	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		points[i] = make_pair(x, y);
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			pq.push({i,j});
		}

	}

	while (!pq.empty())
	{
		line_info topInfo;
		topInfo = pq.top();
		pq.pop();

		if (FindParent(topInfo.start) != FindParent(topInfo.goal))
		{
			res.push_back({ topInfo.start,topInfo.goal });
			Union(topInfo.start, topInfo.goal);
		}


	}

	double sum = 0;
	for (int i = 0; i < res.size(); i++)
	{
		sum += res[i].value();
	}
	cout.precision(3);
	cout << sum << endl;
	return 0;

}