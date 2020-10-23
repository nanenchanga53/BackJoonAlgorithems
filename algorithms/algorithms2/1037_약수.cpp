#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main()
{
	//중앙 값을 기준으로 처음과 마지막수 2개를 곱하면 된다
	// 2 4 = 8
	// 2 4 8 = 16
	// 2 3 5 10 15 = 30 //2 3 5 만 입력될 수 없다.


	int n;
	int nums[51],midNum;

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	sort(nums, nums + n);

	cout << nums[0] * nums[n - 1];

	return 0;
}