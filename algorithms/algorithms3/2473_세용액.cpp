#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n;
long long arr[5001] = { 0, };

int a, b, c;
int m = 3000000001;
int sum = 3000000001;

int main()
{
	a = 0;
	b = 1;
	c = 2;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int l = 0; l < n - 2; l++)
	{
		int mid = l + 1;
		int r = n - 1;
		int x = mid, y = r;

		while (mid < r)
		{
			if (abs(arr[l] + arr[mid] + arr[r]) < abs(arr[x] + arr[y] + arr[l]))
			{
				x = mid;
				y = r;
			}

			if (arr[l] + arr[mid] + arr[r] > 0)
			{
				r--;
			}
			else
			{
				mid++;
			}
		}
		if (abs(arr[l] + arr[x] + arr[y]) < abs(arr[a] + arr[b] + arr[c]))
		{
			a = l;
			b = x;
			c = y;
		}
	}
	
	cout << arr[a] << ' ' << arr[b] << ' ' << arr[c] << endl;

	system("pause");

	return 0;
}
