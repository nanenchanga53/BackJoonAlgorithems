#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int i,j, n,sum;
	sum = 0;
	vector<int> minian(9);
	for (i = 0; i < 9; i++)
	{
		cin >> minian[i];
		sum += minian[i];
	}
	sort(minian.begin(), minian.end());
	
	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (sum - minian[i] - minian[j] == 100)
			{
				minian.erase(minian.begin() + j);
				minian.erase(minian.begin() + i);
				break;
			}
		}
		if (minian.size() != 9)
			break;
	}

	for (i = 0; i < minian.size(); i++)
		cout << minian[i] << endl;

	system("pause");
	return 0;
}