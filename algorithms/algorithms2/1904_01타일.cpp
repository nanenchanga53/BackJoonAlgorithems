#include<iostream>
#include<cmath>
#define mod 15746
using namespace std;
long long i, n;
long long pibo[1000001] = { 0,1,2, };
//�Ǻ���ġ �����ε� ���ۼ��� 1 2 �̴�
int main()
{

	for (int i = 3; i <= 1000000; i++)
		pibo[i] = pibo[i - 1] % mod + pibo[i - 2] % mod;

	cin >> n;

	cout << pibo[n] % mod << endl;

	return 0;
}