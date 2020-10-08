#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
#define MAXNUM 3000

int t, n;
int camp[MAXNUM][3];
int parent[MAXNUM];

//유니온파인드(트리나 그래프 부모찾기)
int find(int x) 
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}
//////////////////////////////////////////////
void merge(int x, int y) 
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;
	else
		parent[x] = y;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> camp[i][0] >> camp[i][1] >> camp[i][2];
			parent[i] = i;
		}

		int cnt = n;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = camp[i][0] - camp[j][0];
				int y = camp[i][1] - camp[j][1];
				int r = camp[i][2] + camp[j][2];
				int d = x*x + y*y;

				if (d <= r * r) {
					if (find(i) != find(j)) {
						merge(i, j);
						cnt--;
					}
				}
			}
		}

		cout << cnt << endl;
	}
	system("pause");
	return 0;
}
