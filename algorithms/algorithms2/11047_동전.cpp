#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int n, k;
int coins[1000001] = { 0, };
int bigCoin = 0;
int cnt = 0;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		//입력은 오름차순
		cin >> coins[i];
		if (k >= coins[i]) bigCoin = i;
	}

	//입력이 오름차순이고 동전이 무조건 2배이상의 가치라 큰 돈전부터 무조건 써보면 된다. 주의할껀 못만드는 경우
	for (int i = bigCoin; i >= 1; i--)
	{
		if (k >= coins[i])
		{
			cnt += (k / coins[i]);
			k = k % coins[i];
		}
	}

	cout << cnt;

	return 0;
}