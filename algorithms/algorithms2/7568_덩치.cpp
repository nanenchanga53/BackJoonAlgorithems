#include<iostream>
#include<algorithm>
using namespace std;

struct impo
{
	int heigh;
	int weight;
	int rank;
};

int main()
{
	int n, v;
	cin >> n;

	impo student[51];

	for (int i = 0; i < n; i++)
	{
		cin >> student[i].weight;
		cin >> student[i].heigh;
		student[i].rank = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (student[j].heigh < student[i].heigh && student[j].weight < student[i].weight)
			{
				student[j].rank++;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << student[i].rank << " ";

	system("pause");
	return 0;
}