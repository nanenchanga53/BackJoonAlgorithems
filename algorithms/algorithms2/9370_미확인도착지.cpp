#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include <climits>
using namespace std;

const int INF = 1000000007; //#define���� �ٲٶ� ���´�

struct line_info
{
	int now;
	int value;
};

bool operator < (line_info t, line_info u)
{
	return t.value > u.value;
}

int T; //�׽�Ʈ���̽�
int n, m, t; //������, ����, ������ �ĺ� ����
int s, g, h; //���������� �����, g-h �������� ������ ����
int a, b, d; // a �� b ���̿� d���� ����� ����
int x; //t ���� ������ �ĺ�

int loads[2001][2001]; //�� ���� loads[a][b] a��ġ���� b�� ��ġ�� �̵������ϸ� c�� ������ �ִ�. ���δ� 1��
vector<int> goals; // ��������


/// <summary>
/// ��������κ��� �ٸ� �������� �ִܰŸ� �˻�(���ͽ�Ʈ��)
/// </summary>
/// <param name="start">�����</param>
/// <returns></returns>
vector<int> dijkstra(const int& start)
{
	//�� ������ �̵��ϴµ� �ʿ��� �ð�
	vector<int> dist(n + 1, INF); //memset �� 0�� -1 �� �Ǿ �׳� ���͸� ���
	dist[start] = 0;
	
	priority_queue<line_info> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int cost = pq.top().value;
		int here = pq.top().now;
		pq.pop();

		//�� ���� �ڽ�Ʈ�� ã�´�
		if (cost <= dist[here])
		{
			for (int i = 1; i <= n; i++)
			{
				if (i == here || loads[here][i] == -1) continue;
				
				int nextCost = cost + loads[here][i];
				//�ִܰ�� ����
				if (nextCost < dist[i])
				{
					dist[i] = nextCost;
					pq.push({ i,nextCost });
				}

			}

		}
	}

	return dist;
}

//��Ʈ�� s - g - h - ������  Ȥ�� s - h - g - ������ �� �Ѵ��� ª���� �����ϸ� �� ���̴�. 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> T;
	for (int test = 0; test < T; test++)
	{
		memset(loads, -1, sizeof(int) * 2001 * 2001);
		goals.clear();

		cin >> n >> m >> t;
		cin >> s >> g >> h;
		
		for (int lineCnt = 0; lineCnt < m; lineCnt++)
		{
			cin >> a >> b >> d;
			loads[a][b] = d;
			loads[b][a] = d;
		}

		for (int goalCnt = 0; goalCnt < t; goalCnt++)
		{
			cin >> x;
			goals.push_back(x);
		}

		sort(goals.begin(), goals.end());

		vector<int> root = dijkstra(s);
		vector<int> branch1 = dijkstra(g);
		vector<int> branch2 = dijkstra(h);

		vector<int> ret;
		for (int i = 1; i <= n; i++)
		{
			//������������ i�� ���ñ��� �ɸ� cost�� g,h���� �����ؼ� ���ư� cost�� ������� ret�� ����
			if (root[i] == root[g] + branch1[h] + branch2[i] || root[i] == root[h] + branch2[g] + branch1[i])
			{
				ret.push_back(i);
			}
		}

		for (int i = 0; i < goals.size(); i++)
		{
			int here = goals[i];
			for (int j = 0; j < ret.size(); j++)
			{
				if (here == ret[j])
					cout << here << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}