#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int n, m;

bool BinarySerch(int exsitNum)
{
	int left, mid, right;

	left = 0;
	right = n - 1;
	

	if (arr[left] > exsitNum || arr[right] < exsitNum)
	{
		return false;
	}

	while (right - left >= 0)
	{
		mid = (left + right) / 2;

		if (arr[mid] > exsitNum)
		{
			right = mid - 1;
		}
		else if (arr[mid] < exsitNum)
		{
			left = mid + 1;
		}
		else
		{
			return true;

		}
	}
	
	return false;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> m;

	sort(arr, arr + n);

	int exsitNum=0, lastNum=0;


	for (int i = 0; i < m; i++)
	{
		cin >> exsitNum;

		cout << (BinarySerch(exsitNum) ? 1 : 0) << endl;
	}

	system("pause");
	return 0;
}
