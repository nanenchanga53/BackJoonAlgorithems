#include <cstdio>
#include <algorithm>
using namespace std;

struct Number {
	int num, idx;
};

int n;
Number num[100001];

bool cmp(const Number &first, const Number &second)
{
	return first.num < second.num;
}

int main()
{
	int m;
	int i, j;
	int s, e, k;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i].num);
		num[i].idx = i;
	}

	sort(num + 1, num + n + 1, cmp);

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &e, &k);

		int cnt = 0;
		for (j = 1; j <= n; j++) {
			if (num[j].idx >= s && num[j].idx <= e)    cnt++;
			if (cnt == k) {
				printf("%d\n", num[j].num);
				break;
			}
		}
	}

	return 0;
}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//#define MAX_NUM 100001
//
//int n, m;
//vector<int> num;
//vector<vector<int>> segment_num;
//int readInt()
//{
//	bool minus = false;
//	int result = 0;
//	char ch;
//	ch = getchar();
//	while (true) {
//		if (ch == '-') break;
//		if (ch >= '0' && ch <= '9') break;
//		ch = getchar();
//	}
//	if (ch == '-') minus = true; else result = ch - '0';
//	while (true) {
//		ch = getchar();
//		if (ch < '0' || ch > '9') break;
//		result = result * 10 + (ch - '0');
//	}
//	if (minus)
//		return -result;
//	else
//		return result;
//}
//
//void segment_init(vector<int> &a, vector<vector<int>> &tree, int node, int start, int end) 
//{
//	if (start == end)
//	{
//		tree[node].push_back(a[start]);
//		return;
//	}
//	else
//	{
//		for (int i = start; i <= end; i++)
//		{
//			tree[node].push_back(a[i]);
//		}
//		sort(tree[node].begin(), tree[node].end());
//		segment_init(a, tree, node * 2, start, (start + end) / 2);
//		segment_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
//	}
//
//	/*if (start == end) {
//		return tree[node] = a[start];
//	}
//	else {
//		return tree[node] = segment_init(a, tree, node * 2, start, (start + end) / 2) + segment_init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
//	}*/
//}
//
//int serch_q(vector<vector<int>> &tree, int node, int start, int end, int left, int right, int k, int bignum) 
//{
//	if (left > end || right < start) 
//	{	
//		return 0;
//	}
//	if (left <= start && end <= right) 
//	{
//		int big;
//		big = 
//	}
//	serch_q(tree, node * 2, start, (start + end) / 2, left, right, k);
//	serch_q(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right, k);
//	
//	
//}
//
//
//int main()
//{
//	int x, y, k;
//
//	n = readInt();
//	m = readInt();
//	
//	for (int i = 0; i < n; i++)
//	{
//		int t;
//		cin >> t;
//		num.push_back(t);
//	}
//	int h = (int)ceil(log2(n));
//	int tree_size = (1 << (h + 1));
//	segment_num.resize(tree_size);
//	segment_init(num, segment_num, 1, 0, n - 1);
//
//	while (m--)
//	{
//		vector<int> range;
//		x = readInt();
//		y = readInt();
//		k = readInt();
//		int v = serch_q(segment_num, 1, 0, n - 1, x-1, y-1, k, -1000000001);
//		
//		cout << v << endl;
//	}
//	
//	system("pause");
//
//	return 0;
//}