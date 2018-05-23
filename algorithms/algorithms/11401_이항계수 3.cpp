#include <iostream>
using namespace std;
const long long mod = 1e9 + 7;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

//x^y = {È¦¼ö½Ã x * (x*x)^(n-1)/2    Â¦¼ö½Ã : (x*x)^(n/2)

long long mul(long long x, long long y, long long p) {
	long long ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}

int main()
{
	long long n, k;

	cin >> n >> k;
	k = min(k, n - k);

	long long ans = 1;
	long long t1 = 1;
	long long t2 = 1;

	for (long long i = 1; i <= n; i++) {
		t1 *= i;
		t1 %= mod;
	}
	for (long long i = 1; i <= k; i++) {
		t2 *= i;
		t2 %= mod;
	}
	for (long long i = 1; i <= n - k; i++) {
		t2 *= i;
		t2 %= mod;
	}

	long long t3 = mul(t2, mod - 2, mod);
	t3 %= mod;
	ans = t1*t3;
	ans %= mod;
	cout << ans << '\n';

	system("pause");
	return 0;
}