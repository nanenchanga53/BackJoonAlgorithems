#include <iostream> 
#include <vector> 
#include <queue> 
#include <algorithm>

using namespace std;

struct pre
{
	long long q;
	int p;
	bool c;
};


int main()
{
	long long n, cn;
	cin >> n;

	cn = n;

	vector<long long> v;

	for (long long i = 2; i*i <= n; i++)
	{
		if (n%i) continue;
		else 
		{
			while (!(n%i))n /= i;
			v.push_back(i);
		}
	}

	if (n != 1)
		v.push_back(n);
	n = cn;
	sort(v.begin(), v.end());

	queue<pre> que;
	pre k;
	for (int i = 0; i < v.size(); i++)
	{
		k.q = v[i];
		k.p = i;
		k.c = true;
		que.push(k);
	}

	long long ans = n;

	while (!que.empty())
	{
		k = que.front();
		que.pop();

		if (k.c)
		{
			ans -= n / k.q;
		}
		else
		{
			ans += n / k.q;
		}

		for (int i = k.p + 1; i < v.size(); i++)
		{
			long long nm = k.q * v[i];
			if (nm <= n)
			{
				pre res;
				res.q = nm;
				res.c = (!k.c);
				res.p = i;
				que.push(res);
			}
			else
			{
				break;
			}

		}
	}

	cout << ans << endl;

	system("pause");
	return 0;
}