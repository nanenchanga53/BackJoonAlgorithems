#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int n, m; //������ ����, ������ ����
int loads[101][101];
int dist[101][101];

const int INF = 10000001; //100000 * 100

void Floyd()
{
	//��� �׷��� �ʱ�ȭ
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = loads[i][j];
	
	//�߰� ���
	for (int k = 1; k <= n; k++)
	{
		//��� ���
		for (int i = 1; i <=n;  i++)
		{
			//���� ���
			for (int j = 1; j <= n; j++)
			{
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

	int a, b, c; //���۵���, ��������, ���

		
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			loads[i][j] = (i == j ? 0 : INF);

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		loads[a][b] = min(loads[a][b] , c);
	}

	Floyd();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' '; //�� �� ������ 0���� �����
		}
		cout << '\n';
	}

	return 0;
}