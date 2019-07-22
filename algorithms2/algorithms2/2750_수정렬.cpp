#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int n;
vector<int> vec;

int main()
{
	int t;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;

		vec.push_back(t);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
		cout << vec[i] << endl;

	system("pause");

	return 0;
}