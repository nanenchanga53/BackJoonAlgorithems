#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
#include<queue>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, num;
	string op;
	queue<int> que;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		que.push(i);
	}

	while (que.size() > 1)
	{
		que.pop();
		num = que.front();
		que.pop();
		que.push(num);
		
	}

	cout << que.front();
	return 0;
}