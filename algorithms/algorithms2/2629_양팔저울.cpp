#include <iostream>
#include <vector>
using namespace std;

int n, x, weight[31],beads;
bool dp[31][15001];

void WeightSolve(int i, int w)
{
	if (i > n || dp[i][w]) return;
	dp[i][w] = true;
	WeightSolve(i + 1, w + weight[i]);
	WeightSolve(i + 1, abs(w - weight[i]));
	WeightSolve(i + 1, w);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}

	WeightSolve(0, 0);

	cin >> beads;

	for (int i = 0; i < beads; i++)
	{
		cin >> x;
		if (x > 15000) cout << "N ";
		else if (dp[n][x]) cout << "Y ";
		else cout << "N ";
	}

	return 0;
}