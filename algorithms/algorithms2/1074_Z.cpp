#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long solve(long long n, long long r, long long c) {
	long long tmp = 0;
	if (n == 2) {
		if (r == 1 && c == 1)
			return 1;
		else if (r == 1 && c == 2)
			return 2;
		else if (r == 2 && c == 1)
			return 3;
		else if (r == 2 && c == 2)
			return 4;
	}
	int mid = n / 2;
	if (r > mid&&c > mid) { /*4*/
							//res = (res + (n*n * 3) / 4) + solve(mid, r - mid, c - mid);
		tmp = tmp + solve(mid, r - mid, c - mid) + ((n*n * 3) / 4);
	}
	else if (r > mid&&c <= mid) { /*3*/
								  //res = (res + (n*n * 2) / 4) + solve(mid, r - mid, c);

		tmp = tmp + solve(mid, r - mid, c) + ((n*n * 2) / 4);
	}
	else if (r <= mid&&c <= mid) { /*2*/
								   //res = (res + (n*n * 0) / 4) + solve(mid, r, c);
		tmp = tmp + solve(mid, r, c) + ((n*n * 0) / 4);
	}
	else if (r <= mid&&c > mid) { /*1*/
								  //res = (res + (n*n * 1) / 4) + solve(mid, r, c - mid);
		tmp = tmp + solve(mid, r, c - mid) + ((n*n * 1) / 4);
	}
	return tmp;
};
int main()
{
	long long N, r, c; //row, col
	cin >> N >> r >> c;
	//1,2,3,4»çºÐ¸é
	long long answer = 0;
	if (N == 1) {
		if (r == 0 && c == 0) {
			cout << 0 << endl;
		}
		else if (r == 0 && c == 1) {
			cout << 1 << endl;
		}
		else if (r == 1 && c == 0) {
			cout << 2 << endl;
		}
		else if (r == 1 && c == 1) {
			cout << 3 << endl;
		}
	}
	else {
		long long n = (long long)pow(2, N);
		// N <= 15
		// n <= 32768
		// 1073741824
		answer = solve(n, r + 1, c + 1);
		--answer;
		cout << answer << endl;
	}
	system("pause");
	return 0;
}