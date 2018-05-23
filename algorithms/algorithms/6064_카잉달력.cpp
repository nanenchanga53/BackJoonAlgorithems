#include<iostream>
#include<cmath>
using namespace std;

int lest_lcm(int, int, int, int, int);
int lcm(int, int);
int gcd(int, int);

int main()
{
	int T, i;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int M, N, x, y;
		int max_year, now_year;

		cin >> M >> N >> x >> y;

		max_year = lcm(M, N);
		now_year = lest_lcm(M, N, x, y, max_year);

		cout << now_year << endl;
	}

	system("pause");
	return 0;
}

int lest_lcm(int M, int N, int a, int b, int max_year)
{
	while (a != b && max_year > a && max_year > b)
	{
		if (a < b)
			a += M;
		else if (b < a)
			b += N;
		else
			break;
	}

	if (a != b)
		return -1;
	else
		return a;
}

int lcm(int a, int b) {
	int gcd_value = gcd(a, b);

	if (gcd_value == 0) return 0;  // 인수가 둘다 0일 때의 에러 처리

	return abs((a * b) / gcd_value);
}

// 최대 공약수 계산 함수; 최소 공배수 계산에 사용됨
// (Euclidean Algorithm; Euclid's Algorithm)
int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	return abs(a);
}