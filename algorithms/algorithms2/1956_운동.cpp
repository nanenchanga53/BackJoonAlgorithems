#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int v, e; //마을개수, 도로개수
int loads[401][401];
int dist[401][401];

const int INF = 4000001; //10000 * 400

void Floyd()
{
	//결과 그래프 초기화
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			dist[i][j] = loads[i][j];

	//중간 노드
	for (int k = 1; k <= v; k++)
	{
		//출발 노드
		for (int i = 1; i <= v; i++)
		{
			if (k == i) continue;
			//도착 노드
			for (int j = 1; j <= v; j++)
			{
				if (j == k) continue;

				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}

		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int a, b, c; //시작마을, 도착마을, 거리


	cin >> v;
	cin >> e;

	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			loads[i][j] = INF;    //i == j 때도 자기 자신으로 돌아올 수 있도록 최대값을 넣는다.

	for (int i = 1; i <= e; i++)
	{
		cin >> a >> b >> c;
		loads[a][b] = min(loads[a][b], c);
	}

	Floyd();

	int res = INF;
	for (int i = 1; i <= v; i++)
	{
		res = min(dist[i][i], res);
	}
	
	cout << (res == INF ? -1 : res) << '\n';

	return 0;
}