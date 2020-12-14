#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int parent[201];

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

	cin >> n;
	cin >> m;

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	int isLinked, town1, town2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> isLinked;
			if (isLinked == 1)
			{
				town1 = FindParent(i); //ã������ ����(����)�� �ְ� �θ� �����´�
				town2 = FindParent(j); //ã������ ����(����)�� �ְ� �θ� �����´�
				if (town1 != town2) //�ְ� �θ� �ٸ��� ������ �ְ� �θ� �ٸ����� �ְ� �θ� ����Ű�� �Ѵ�
				{
					parent[town2] = town1;
				}
			}
		}
	}

	int townNum,parentNum;
	cin >> townNum;
	parentNum = FindParent(townNum);
	for (int i = 1; i < m; i++)
	{
		cin >> townNum;
		if (parentNum != FindParent(townNum))
		{
			cout << "NO\n";
			return 0;
		}

	}
	cout << "YES\n";
	return 0;

}