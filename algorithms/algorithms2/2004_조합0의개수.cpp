#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

//2가 사용된 개수 구하기 n!이니 2 4 8 .... n보다 작은 2의 배수는 썼을 것이다 아래껀 큰수부터 작은수 개수를 센다
long long TowCnt(long long num)
{
	int cnt = 0;
	for (long long i = 2; i <= num; i *= 2)
	{
		cnt += num / i;
	}
	return cnt;
}

//2가 사용된 개수 구하기 n!이니 2 4 8 .... n보다 작은 2의 배수는 썼을 것이다 아래껀 큰수부터 작은수 개수를 센다 125라면 125는 한번 25는 5번 5는 25번 사용 
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
	//0의 개수니 곱셈에서 10이 되는경우는 2 * 5 즉 10 의 개수를 세면된다. n!의 10의개수 - r!의 10의개수 - (n-r)!의 10의개수
	//각각의 10의 개수는 2,5 개수를 따로 센후 작은것만 쓰면 된다.
	
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