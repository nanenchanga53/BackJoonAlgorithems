#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n = 10,target; //받아오는 개수, 나누는 수
	int nums[42];//42을 나눈 나머지의 숫자를 세면 되기때문에 배열크기는 더 클 필요없다.
	int cnt; // 서로다른 나머지 개수
	memset(nums, 0, sizeof(nums));


	for (int i = 1; i <= n; i++)
	{
		cin >> target;

		nums[target % 42]++;
	}

	cnt = 0;

	for (int i = 0; i <= 41; i++)
	{
		if (nums[i] > 0)
			cnt++;
	}

	cout << cnt << endl;


	return 0;
}