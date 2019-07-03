#include<iostream>
#include<climits>  //최대최솟값이 정의된 헤더
using namespace std;
int main()
{
	int n;
	int min, max; //최솟값 최댓값
	int nums[1000001];//사실 배열을 만들필요는 없다

	min = INT_MAX;//int형 최대값을 넣어준다
	max = INT_MIN;//int형 최솟값을 넣어준다

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