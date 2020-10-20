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
		//�Է��� ��������
		cin >> coins[i];
		if (k >= coins[i]) bigCoin = i;
	}

	//�Է��� ���������̰� ������ ������ 2���̻��� ��ġ�� ū �������� ������ �Ẹ�� �ȴ�. �����Ҳ� ������� ���
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