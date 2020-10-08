#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
int l, n, x;
deque<pair<int, int>> dq;
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++) 
	{
		while (dq.size() && dq.front().second <= i - l)
			dq.pop_front();

		scanf("%d", &x);

		while (dq.size() && dq.back().first >= x)
			dq.pop_back();
		dq.push_back({ x,i });
		printf("%d ", dq.front().first);
	}
	return 0;
}
