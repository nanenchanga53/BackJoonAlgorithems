#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int v, e; //��������, ���ΰ���
int loads[401][401];
int dist[401][401];

const int INF = 4000001; //10000 * 400

void Floyd()
{
	//��� �׷��� �ʱ�ȭ
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			dist[i][j] = loads[i][j];

	//�߰� ���
	for (int k = 1; k <= v; k++)
	{
		//��� ���
		for (int i = 1; i <= v; i++)
		{
			if (k == i) continue;
			//���� ���
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

	int a, b, c; //���۸���, ��������, �Ÿ�


	cin >> v;
	cin >> e;

	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			loads[i][j] = INF;    //i == j ���� �ڱ� �ڽ����� ���ƿ� �� �ֵ��� �ִ밪�� �ִ´�.

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