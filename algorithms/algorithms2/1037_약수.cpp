#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main()
{
	//�߾� ���� �������� ó���� �������� 2���� ���ϸ� �ȴ�
	// 2 4 = 8
	// 2 4 8 = 16
	// 2 3 5 10 15 = 30 //2 3 5 �� �Էµ� �� ����.


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