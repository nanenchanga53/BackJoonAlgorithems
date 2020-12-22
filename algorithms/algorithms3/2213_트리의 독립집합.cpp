#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;

//�������� : Ʈ������ ���� ����Ǿ� ���� ���� �͵��� ����
//a-b-c �̷��� ����Ǿ� ������ a,c �� �����ϴ� ��Ȳ�� ���������̴�.
//��ǥ�� ���� ����ġ�� ū ���������� ���ϴ� ��
//��� ��Ȳ�� ã�ƾ��ϰ� Ȯ���� ���� ���̱� ���� dp�� �̿��Ѵ�.
//dp�� ���� v�� ��Ʈ���ϴ� ����Ʈ���� ���������� ���Ѵ�(dfs�� �Ʒ����� ���� �ö󰡵��� �����)
//dp[v][0] : ���� v�� �������տ� ���Ե��� ���� ��� �ִ�
//dp[v][1] : ���� v�� �������տ� ���Ե� ��쿡 �ִ�

const int MAXNUM = 100001;
int n;
int w[MAXNUM];
int dp[MAXNUM][2];
vector<vector<int>> edge;
vector<int> res;

void dfs(int now, int parent)
{
	//��� ����
	for (int i = 0; i < edge[now].size(); i++)
	{
		if (edge[now][i] == parent) continue;
		else dfs(edge[now][i], now); // �ڽ���ġ�� ������ġ��, ������ġ�� �� �θ�� �˻�
	}

	dp[now][0] = 0; //now��带 ������
	dp[now][1] = w[now]; // now��带 �����ϴ� ���� �����ְ� ����
	for (int i = 0; i < edge[now].size(); i++) //���� ��ġ���� ��� �ڽĵ� �˻�
	{
		if (edge[now][i] == parent) continue;

		dp[now][0] += max(dp[edge[now][i]][0], dp[edge[now][i]][1]); // max( ����� �ڽĵ��� ���� ���� ��, ����� �ڽ��� ������ ��)
		dp[now][1] += dp[edge[now][i]][0]; // ����� �ڽ��� �������ϴ� �ִ밪 + wight[now];
	}

}

void trace(int now, bool isInclude, int parent) 
{
	if (isInclude == true) //������ ���
	{ 
		res.push_back(now); //����������
		for (int i = 0; i < edge[now].size(); i++) 
		{
			if (edge[now][i] == parent) continue;
			trace(edge[now][i], false, now); //�θ� �����̸� �ڽĵ��� ������ �� ��������
		}
	}
	else //���� �ƴϸ�
	{ 
		for (int i = 0; i < edge[now].size(); i++) //��� �ڽĵ鿡 ����
		{ 
			if (edge[now][i] == parent) continue;

			if (dp[edge[now][i]][0] < dp[edge[now][i]][1]) 
				trace(edge[now][i], true, now); //�ڽĵ� �����̸�

			else trace(edge[now][i], false, now); //���� �ƴϸ�
		}
	}
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	edge.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}

	
	int a, b;
	
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1, 0); //1�� �������� �ΰ� dp
	cout << max(dp[1][0], dp[1][1]) << '\n';

	if (dp[1][0] > dp[1][1])
	{
		trace(1, false, 0);
	}
	else
	{
		trace(1, true, 0);
	}

	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}

	return 0;

}