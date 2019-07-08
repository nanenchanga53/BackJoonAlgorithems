// r , r'  각 원의 반지름   d  원의 중심 끼리의 길이
//외접 r + r' = d   1가지 //곱
//내접 r - r' = d   1가지
//완전히 겹치는 원  무한으로 만난다 d=0 -1가지
//만나지 않고 큰원 안에 작은 원  d < r'-r  0가지
//아예 안만남 r + r' < d  0가지
//그외는 서로 두 개의 교차점 r'-r < d < r' + r 2가지
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;


int main()
{
	int n;
	int x1, y1, x2, y2, r1, r2;
	int d, rSum, rMin;
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		d = pow((x1 - x2), 2) + pow((y1 - y2), 2);
		rSum = r1 + r2;
		rMin = abs(r1 - r2);

		if (x1 == x2 && y1 == y2)// 중점이 같을때
		{
			if (r1 == r2) //반지름이 같을때
				res = -1;
			else //반지름이 다를때
				res = 0;
		}
		else //중점이 다를때
		{
			if (rMin < sqrt(d) && sqrt(d) < rSum) // 2개 교차점
				res = 2;
			else if (rMin == sqrt(d)) // 내접
				res = 1;
			else if (rSum == sqrt(d)) // 외접
				res = 1;
			else if (rSum < sqrt(d)) //만나지 않는 원
				res = 0;
			else if (sqrt(d) == rSum) //외접
				res = 1;
			else if (sqrt(d) < rMin) //중심이 다르고 만나지 않는 원
				res = 0;
		}	

		cout << res << endl;
	}
	return 0;
}