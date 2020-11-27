#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int n; // ������ ��
string nums[16]; // ���տ� ���Ե� �� string
int k; //������ ��
long long dp[1 << 15][101]; //[��Ʈ����ŷ(���ġ���ڸ��質)][k�� ���������� ������]


//("12345" * 1000 + "678") mod K == ("12345" * 1000) mod K + "678" mod K  == ("12345" mod K) * '(1000 mod K)' + ("678" mod K)   �� �̿����� 
int ten[51]; // ���� 1000 mod K ���� ���� �̸� ���� : 10�� i������ mod ���� ����
int mods[16] = { 0, }; // �̸� �� ������ ���� mod���� ����
int lens[16]; // �� ������ ����

//���� ������ i�̰� �������� j�� ��, i�� ������ ���� l�� ���� �ڿ� �̾�ٿ��� �� �������� next��� �ϸ�
// [ (j * pow( 10, len(l��° ��) ) % k ) % k + l��° �� % k ] % k �� ���� �� �ִ�.

long long s1, s2;//����,�и�
long long gcdRes; //�ִ����� ���

/// <summary>
/// �ִ� �����
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


// ���̳��� 
void park()
{
	dp[0][0] = 1;
	//� ������ ���ڸ� �����
	for (int i = 0; i < (1 << n); i++)
	{
		//������ ��ġ
		for (int j = 0; j < k; j++)
		{
			//���� ���������ϴ� ���� ��ġ
			for (int l = 0; l < n; l++)
			{
				//dp�۾� [ (j * pow( 10, len(l��° ��) ) % k ) % k + l��° �� % k ] % k 
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

	ten[0] = 1; // 10�� 0������ 1;
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