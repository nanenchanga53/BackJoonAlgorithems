#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

struct Meeting
{
	int startTime;
	int endTime;
	
};

//ȸ�ǰ� ������ �ð��� �������� ������������ ����
bool cmp(const Meeting& p1, const Meeting& p2) {
	if (p1.endTime < p2.endTime) {
		return true;
	}
	else if (p1.endTime == p2.endTime) {
		return p1.startTime < p2.startTime;
	}
	else {
		return false;
	}
}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n=0;
	Meeting mt[100001];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> mt[i].startTime >> mt[i].endTime;
	}

	sort(mt, mt + n, cmp);

	int result = 1;
	int endtime = mt[0].endTime;

	//ȸ�ǰ� ���� �����°ź��� ����
	for (int i = 1; i < n; i++)
	{
		if (endtime <= mt[i].startTime)
		{
			result++;
			endtime = mt[i].endTime;
		}
	}

	cout << result;

	return 0;
}