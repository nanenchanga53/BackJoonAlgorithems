#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n = 10,target; //�޾ƿ��� ����, ������ ��
	int nums[42];//42�� ���� �������� ���ڸ� ���� �Ǳ⶧���� �迭ũ��� �� Ŭ �ʿ����.
	int cnt; // ���δٸ� ������ ����
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