#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int MAXNUM = 10001;

int n,m,T;
//int parent[MAXNUM];
//int airLine[MAXNUM][MAXNUM];
//queue<pair<int,int>> que;
//
//int FindParent(int num)
//{
//	if (num == parent[num])
//		return num;
//	else
//	{
//		parent[num] = FindParent(parent[num]);
//		return parent[num];
//	}
//}
//
//void Union(int n1, int n2)
//{
//	n1 = FindParent(n1);
//	n2 = FindParent(n2);
//
//	if (n1 != n2)
//	{
//		parent[n2] = n1;
//	}
//}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int a, b;
	int airportCnt;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
		}
		cout << n - 1 << endl;


	}
	




	return 0;

}