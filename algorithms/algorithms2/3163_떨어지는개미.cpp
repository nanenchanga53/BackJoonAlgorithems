#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MXN = 1e5;
int t, n, l, k;
pair<int, int> p[MXN];
int main() {
	cin >> t;
	while(t--) 
	{
		int c = 0;
		vector<int> v;
		cin >> n >> l >> k;
		for (int i = 0, x; i < n; i++) 
		{
			cin >> x >> p[i].second;
			if (p[i].second < 0) 
				p[c++].first = x;
			else 
				v.push_back(l - x);
		}
		for (int it : v) 
			p[c++].first = it;
		sort(p, p + n);
		cout << p[k - 1].second << endl;
	}

	return 0;
}