#include<iostream>
#include<climits>  //�ִ��ּڰ��� ���ǵ� ���
using namespace std;
int main()
{
	int n;
	int min, max; //�ּڰ� �ִ�
	int nums[1000001];//��� �迭�� �����ʿ�� ����

	min = INT_MAX;//int�� �ִ밪�� �־��ش�
	max = INT_MIN;//int�� �ּڰ��� �־��ش�

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (min > nums[i])
			min = nums[i];

		if (max < nums[i])
			max = nums[i];
	}
	
	cout << min << ' ' << max << endl;


	return 0;
}