#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int n; // 집합의 수
string nums[16]; // 집합에 포함된 수 string
int k; //나누는 수
long long dp[1 << 15][101]; //[비트마스킹(어떤위치숫자를썼나)][k로 나누었을때 나머지]


//("12345" * 1000 + "678") mod K == ("12345" * 1000) mod K + "678" mod K  == ("12345" mod K) * '(1000 mod K)' + ("678" mod K)   을 이용하자 
int ten[51]; // 위의 1000 mod K 등의 값을 미리 저장 : 10의 i제곱의 mod 값을 저장
int mods[16] = { 0, }; // 미리 각 집합의 수의 mod값을 저장
int lens[16]; // 각 숫자의 길이

//현재 집합이 i이고 나머지가 j일 때, i에 속하지 않은 l번 수를 뒤에 이어붙였을 때 나머지를 next라고 하면
// [ (j * pow( 10, len(l번째 수) ) % k ) % k + l번째 수 % k ] % k 로 만들 수 있다.

long long s1, s2;//분자,분모
long long gcdRes; //최대공약수 결과

/// <summary>
/// 최대 공약수
/// </summary>
long long gcd(long long x, long long y)
{
	long long r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}


// 다이나믹 
void park()
{
	dp[0][0] = 1;
	//어떤 지점의 숫자를 썼는지
	for (int i = 0; i < (1 << n); i++)
	{
		//나머지 위치
		for (int j = 0; j < k; j++)
		{
			//현재 넣으려고하는 수의 위치
			for (int l = 0; l < n; l++)
			{
				//dp작업 [ (j * pow( 10, len(l번째 수) ) % k ) % k + l번째 수 % k ] % k 
				if ((i & (1 << l)) == 0)
				{
					int nextNum = j * ten[lens[l]];
					nextNum %= k;
					nextNum += mods[l];
					nextNum %= k;
					dp[i | (1 << l)][nextNum] += dp[i][j];
				}
			}
		}
	}

	s1 = dp[(1 << n) - 1 ][0];
	s2 = 1;
	for (int i = 1; i <= n; i++)
	{
		s2 *= i;
	}

	gcdRes = gcd(s1, s2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;	
	

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		lens[i] = nums[i].length();
	}
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < lens[i]; j++)
		{
			mods[i] = mods[i] * 10 + (nums[i][j] - '0');
			mods[i] %= k;
		}
	}

	ten[0] = 1; // 10의 0제곱은 1;
	for (int i = 1; i <= 50; i++)
	{
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}

	park();
	
	s1 /= gcdRes;
	s2 /= gcdRes;

	cout << s1 << '/' << s2 << '\n';

	return 0;
}