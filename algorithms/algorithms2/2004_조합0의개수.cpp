#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

//2�� ���� ���� ���ϱ� n!�̴� 2 4 8 .... n���� ���� 2�� ����� ���� ���̴� �Ʒ��� ū������ ������ ������ ����
long long TowCnt(long long num)
{
	int cnt = 0;
	for (long long i = 2; i <= num; i *= 2)
	{
		cnt += num / i;
	}
	return cnt;
}

//2�� ���� ���� ���ϱ� n!�̴� 2 4 8 .... n���� ���� 2�� ����� ���� ���̴� �Ʒ��� ū������ ������ ������ ���� 125��� 125�� �ѹ� 25�� 5�� 5�� 25�� ��� 
long long FiveCnt(long long num)
{
	int cnt = 0;
	for (long long i = 5; i <= num; i *= 5)
	{
		cnt += num / i;
	}

	return cnt;
}

int main()
{
	//nCr  =  n! / r!(n-r)!
	//0�� ������ �������� 10�� �Ǵ°��� 2 * 5 �� 10 �� ������ ����ȴ�. n!�� 10�ǰ��� - r!�� 10�ǰ��� - (n-r)!�� 10�ǰ���
	//������ 10�� ������ 2,5 ������ ���� ���� �����͸� ���� �ȴ�.
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	long long n, r;
	long long zeroCount = 0;
	long long towCount = 0, fiveCount = 0;
	cin >> n >> r;

	towCount = TowCnt(n) - (TowCnt(r) + TowCnt(n - r));
	fiveCount = FiveCnt(n) - (FiveCnt(r) + FiveCnt(n - r));

	zeroCount = min(towCount,fiveCount);

	cout << zeroCount << '\n';

	return 0;
}