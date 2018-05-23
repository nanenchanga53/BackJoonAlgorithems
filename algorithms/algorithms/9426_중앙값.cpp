#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int w[250001];
int n, k, t, ans, tmp;
long long sum = 0;
multiset<int> low, high;
multiset<int>::iterator it;
void lpop(int &ans)
{
	it = --low.end();
	tmp = ans;
	ans = *it;
	low.erase(it);
	high.insert(tmp);
}
void hpop(int &ans)
{
	it = high.begin();
	tmp = ans;
	ans = *it;
	high.erase(it);
	low.insert(tmp);
}
int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i], sum += w[i];
	ans = w[1];
	if (k == 1) return cout << sum, 0;
	sum = 0;
	for (int i = 2; i <= n; i++)
	{
		t = w[i];
		if (t >= ans) high.insert(t);
		else
		{
			if (!low.size())
			{
				high.insert(ans);
				ans = t;
			}
			else
			{
				low.insert(t);
				lpop(ans);
			}
		}
		int lsz = low.size(), hsz = high.size();
		if (abs(lsz - hsz) > 1)
		{
			(lsz > hsz) ? lpop(ans) : hpop(ans);
		}
		if (i >= k)
		{
			sum += ans;
			int elem = w[i - k + 1];
			if (elem < ans) low.erase(elem);
			else
			{
				if (high.count(elem)) high.erase(elem);
				else
				{
					hpop(ans);
					low.erase(elem);
				}
			}
		}
	}
	cout << sum;
}