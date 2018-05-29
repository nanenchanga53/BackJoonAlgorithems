#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n;
int arr[100001] = { 0, };
	
int i,mi,mj;
int m = 2000000001;
int sum = 2000000001;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);
	
	i = 0;
	n--;

	while (i != n)
	{
		sum = arr[i] + arr[n];

		if (abs(sum) < m)
		{
			mi = arr[i];
			mj = arr[n];
			m = abs(sum);
		}

		if (sum > 0)
		{
			n--;
		}
		else if (sum < 0)
		{
			i++;
		}
		else
		{
			break;
		}
	}
	cout << mi << " " << mj << endl;
	system("pause");

	return 0;
}
