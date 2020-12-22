#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;

//독립집합 : 트리에서 서로 연결되어 있지 않은 것들의 집합
//a-b-c 이렇게 연결되어 있으면 a,c 를 선택하는 상황이 독립집합이다.
//목표는 가장 가중치가 큰 독립집합을 구하는 것
//모든 상황을 찾아야하고 확인의 수를 줄이기 위해 dp를 이용한다.
//dp는 정점 v를 루트로하는 서브트리의 독립집합을 구한다(dfs로 아래에서 위로 올라가도록 만든다)
//dp[v][0] : 정점 v가 독립집합에 포함되지 않은 경우 최댓값
//dp[v][1] : 정점 v가 독립집합에 포함된 경우에 최댓값

const int MAXNUM = 100001;
int n;
int w[MAXNUM];
int dp[MAXNUM][2];
vector<vector<int>> edge;
vector<int> res;

void dfs(int now, int parent)
{
	//모두 돈다
	for (int i = 0; i < edge[now].size(); i++)
	{
		if (edge[now][i] == parent) continue;
		else dfs(edge[now][i], now); // 자식위치를 현재위치로, 현재위치를 그 부모로 검색
	}

	dp[now][0] = 0; //now노드를 미포함
	dp[now][1] = w[now]; // now노드를 포함하는 경우라 값을넣고 시작
	for (int i = 0; i < edge[now].size(); i++) //현재 위치에서 모든 자식들 검색
	{
		if (edge[now][i] == parent) continue;

		dp[now][0] += max(dp[edge[now][i]][0], dp[edge[now][i]][1]); // max( 연결된 자식들을 선택 안할 시, 연결된 자식을 포함할 시)
		dp[now][1] += dp[edge[now][i]][0]; // 연결된 자식을 미포함하는 최대값 + wight[now];
	}

}

void trace(int now, bool isInclude, int parent) 
{
	if (isInclude == true) //포함인 경우
	{ 
		res.push_back(now); //독립집합임
		for (int i = 0; i < edge[now].size(); i++) 
		{
			if (edge[now][i] == parent) continue;
			trace(edge[now][i], false, now); //부모가 포함이면 자식들은 무조건 안 포함으로
		}
	}
	else //포함 아니면
	{ 
		for (int i = 0; i < edge[now].size(); i++) //모든 자식들에 대해
		{ 
			if (edge[now][i] == parent) continue;

			if (dp[edge[now][i]][0] < dp[edge[now][i]][1]) 
				trace(edge[now][i], true, now); //자식도 포함이면

			else trace(edge[now][i], false, now); //포함 아니면
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

	dfs(1, 0); //1을 정점으로 두고 dp
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