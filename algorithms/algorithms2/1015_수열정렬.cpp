#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct BP
{
	int num;
	int point;
};

bool cmp(const BP &u, const BP &v)
{
	if (u.num < v.num)
		return true;
	else if(u.num > v.num)
	{
		return false;
	}
	else
	{
		if (u.point < v.point)
			return true;
		else
			return false;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;

	vector<BP> arr(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].num;
		arr[i].point = i;
	}

	sort(arr.begin(), arr.end(), cmp);

	int p[51];

	for (int i = 0; i < n; i++)
	{
		p[arr[i].point] = i;
	}

	for (int i = 0; i < n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}