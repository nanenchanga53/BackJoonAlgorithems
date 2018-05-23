#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

queue<int> qu;
stack<int> st;
vector<int> vec[1001];
int n, m, v;
bool check[1001];

void dfs(int nv);

void myfunc_dfs(int var)
{
	if (check[var] == false)
	{
		dfs(var);
	}
}

void dfs(int nv)
{
	int i;
	st.push(nv);
	check[nv] = true;
	printf("%d ", nv);

	//for each (int var in vec[nv])
	//{
	//	if (check[var] == false)
	//	{
	//		dfs(var);
	//	}
	//}

	for_each(vec[nv].begin(), vec[nv].end(), myfunc_dfs);

	st.pop();
	return;
}

void myfunc(int var)
{
	if (check[var] == false)
	{
		qu.push(var);
		check[var] = true;
	}
}

void bfs()
{
	int i;
	int nv;

	if (qu.empty())
		return;

	nv = qu.front();
	qu.pop();

	printf("%d ", nv);

	//for each(int var in vec[nv])
	//{
	//	if (check[var] == false)
	//	{
	//		qu.push(var);
	//		check[var] = true;
	//	}
	//}

	for_each(vec[nv].begin(), vec[nv].end(), myfunc);

	bfs();
}

int main()
{
	int i, j;
	int t1, t2;
	scanf("%d %d %d", &n, &m, &v);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &t1, &t2);
		vec[t1].push_back(t2);
		vec[t2].push_back(t1);
	}

	for (i = 1; i <= n; i++)
		sort(vec[i].begin(), vec[i].end());

	memset(check, false, sizeof(check));
	dfs(v);
	printf("\n");
	memset(check, false, sizeof(check));
	qu.push(v);
	check[v] = true;
	bfs();

	system("pause");

	return 0;
}