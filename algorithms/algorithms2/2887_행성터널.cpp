#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXNUM = 100001;

int n;
int parent[MAXNUM];

struct StarInfo
{
	int x;
	int y;
	int z;
	int index;
};

bool compX(StarInfo& t, StarInfo& u)
{
	return t.x < u.x;
}

bool compY(StarInfo& t, StarInfo& u)
{
	return t.y < u.y;
}

bool compZ(StarInfo& t, StarInfo& u)
{
	return t.z < u.y;
}

vector<StarInfo> points;

struct LineInfo
{
	int start;
	int goal;
	int value;

};

vector<LineInfo> pq;
vector<LineInfo> res;

bool compLine (LineInfo t, LineInfo u)
{

	return t.value < u.value;
}


int FindParent(int num)
{
	if (num == parent[num])
		return num;
	else
	{
		return parent[num] = FindParent(parent[num]);
	}
}

bool Union(int n1, int n2)
{
	n1 = FindParent(n1);
	n2 = FindParent(n2);

	if (n1 != n2)
	{
		parent[n2] = n1;
		return true;
	}
	else
		return false;

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

	int x, y, z;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y >> z;
		points.push_back({ x,y,z,i });
	}

	sort(points.begin(), points.end(), compX);

	for (int i = 0; i < points.size() - 1; i++)
	{
		LineInfo t;
		t.start = points[i].index;
		t.goal = points[i + 1].index;
		t.value = abs(points[i].x - points[i + 1].x);
		pq.push_back(t);
	}

	sort(points.begin(), points.end(), compY);

	for (int i = 0; i < points.size() - 1; i++)
	{
		LineInfo t;
		t.start = points[i].index;
		t.goal = points[i + 1].index;
		t.value = abs(points[i].y - points[i + 1].y);
		pq.push_back(t);
	}

	sort(points.begin(), points.end(), compZ);

	for (int i = 0; i < points.size() - 1; i++)
	{
		LineInfo t;
		t.start = points[i].index;
		t.goal = points[i + 1].index;
		t.value = abs(points[i].z - points[i + 1].z);
		pq.push_back(t);
	}

	sort(pq.begin(), pq.end(), compLine);

	int lineCnt = 0;
	int sum = 0;
	for(int i = 0; i < pq.size(); i++)
	{
		LineInfo topInfo;
		topInfo = pq[i];

		if (Union(topInfo.start, topInfo.goal))
		{
			sum += topInfo.value;
			//res.push_back({ topInfo.start,topInfo.goal, topInfo.value });
			lineCnt++;
			if (lineCnt == n - 1)
				break;
		}


	}

	
	/*for (int i = 0; i < res.size(); i++)
	{
		sum += res[i].value;
	}*/
	cout << sum << '\n';
	return 0;

}