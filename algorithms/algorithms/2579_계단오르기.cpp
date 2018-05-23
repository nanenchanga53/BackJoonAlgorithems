#include<iostream>
#include<algorithm>
using namespace std;

int score[301] = { 0, };
int sum[301][3] = { 0, };
int n;

int serch()
{
	int stair;
	for (stair = 3; stair <= n; stair++)
	{
		sum[stair][0] = score[stair] + max(sum[stair - 2][0], sum[stair - 2][1]);
		sum[stair][1] = score[stair] + sum[stair - 1][0];
	}

	return max(sum[n][0], sum[n][1]);
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> score[i];
	sum[1][0] = score[1];
	sum[2][0] = score[2];
	sum[2][1] = score[1] + score[2];

	cout << serch() << endl;
	system("pause");
	return 0;
}