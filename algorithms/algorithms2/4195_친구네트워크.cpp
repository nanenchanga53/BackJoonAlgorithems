#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;

int f, nameCount, T;
int parent[200001];
int parentCnt[200001];
map<string, int> names;

int FindParent(int num)
{
	if (num == parent[num])
		return num;
	else
	{
		parent[num] = FindParent(parent[num]);
		return parent[num];
	}
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> T;

	string name1, name2;
	int parentNum1, parentNum2;
	while (T--)
	{
		cin >> f;

		for (int i = 1; i <= 200000; i++)
		{
			parent[i] = i;
			parentCnt[i] = 1;
		}

		nameCount = 0;
		for (int i = 0; i < f; i++)
		{
			cin >> name1 >> name2;
			if (names[name1] == 0)
			{
				names[name1] = ++nameCount;

			}

			if (names[name2] == 0)
			{
				names[name2] = ++nameCount;
			}

			parentNum1 = FindParent(names[name1]);
			parentNum2 = FindParent(names[name2]);

			if (parentNum1 != parentNum2)
			{
				parent[parentNum2] = parentNum1;
				parentCnt[parentNum1] += parentCnt[parentNum2];
			}

			cout << parentCnt[parentNum1] << '\n';
		}

		
	}
	

	
	return 0;

}