#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	int limit = sqrt(m) + 1;

	bool isP[1001002];
	memset(isP, 1, sizeof(isP));

	vector<int> prime;
	prime.push_back(2);

	for (int i=3;i<limit;i+=2)
	{
		if (!isP[i])
			continue;
		prime.push_back(i);

		for (long long j = 1LL * i*i; j < limit; j += i * 2)
		{
			isP[j] = false;
		}
	}

	memset(isP, 1, sizeof(isP));
	for (int p : prime)
	{
		long long t = 1LL * p * p;
		for (long long i = (n%t ? (n / t + 1)*t : n); i <= m; i += t)
		{
			isP[i - n] = false;
		}
	}
	int result = 0;
	for (int i = 0; i < m - n + 1; i++)
	{
		result += isP[i];
	}
	cout << result << endl;
	system("pause");
	return 0;
}