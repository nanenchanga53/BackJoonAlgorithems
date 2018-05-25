#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

int n,l;
int arr[5000001];
deque<int> dq;
vector<int> vc;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> n >> l;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];

		if (dq.empty())
		{
			dq.push_back(arr[i]);
		}
		else
		{
			while (!dq.empty() && dq.back() > arr[i])
				dq.pop_back();

			dq.push_back(arr[i]);
		}

		if (i > l)
		{
			if (dq.front() == arr[i - 1])
			{
				dq.pop_front();
			}
		}

		vc.push_back(dq.front());
	}

	for (int i = 0; i < n; i++)
	{
		cout << vc[i] << endl;
	}
	system("pause");
	return 0;
}