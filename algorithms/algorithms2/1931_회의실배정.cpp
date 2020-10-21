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

//회의가 끝나는 시간을 기준으로 오름차순으로 정렬
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

	//회의가 빨리 끝나는거부터 고른다
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