#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int n, m,T;
int linear[1001];
bool check[1001];
int circle = 0;

void dfs(int now)
{
	check[now] = true;
	if (check[linear[now]] == false)
	{
		dfs(linear[now]);
	}
	else
	{
		circle++;
		return;
	}
}

int main()
{
	int start, end;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	while (T--)
	{
		memset(linear, 0, sizeof(linear));
		memset(check, 0, sizeof(check));
		circle = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> linear[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (check[i] == false)
			{
				dfs(i);
			}
		}
		cout << circle << endl;
	}

	system("pause");
	return 0;

}
