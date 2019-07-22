#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	double average;						//평균
	int many[2] = { 0, }, many_num[2] = { 0, };	//최빈값의 개수, 최빈값
	int range, min = 8000, max = 0;		//범위, 최솟값, 최대값
	int middle = 0;							// 중앙값
	long long sum = 0;						//숫자의 합
	int n, t, num2;

	int number[4001 + 4001] = { 0 };			//숫자의 개수

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		number[t + 4000]++;
		sum += t;
	}
	average = (double)sum / (double)n;
	t = 0;
	num2 = 0;
	for (int i = 0; i < 8002; i++)
	{
		if (number[i] != 0)
		{
			if (i <= min)
				min = i;
			if (i >= max)
				max = i;

			if (num2 < (n + 1) / 2)
			{
				num2 += number[i];
				middle = i;
			}
		}
		if (many[t] < number[i])
		{
			t = 0;
			many[t] = number[i];
			many_num[t] = i;
		}
		else if (many[t] == number[i] && t == 0)
		{
			t++;
			many[t] = number[i];
			many_num[t] = i;
		}
	}
	range = abs(max - min);

	cout << fixed;         //소수점 고정
	cout.precision(0);

	cout << average << endl;
	cout << middle - 4000 << endl;
	cout << many_num[t] - 4000 << endl;
	cout << range << endl;

	return 0;
}