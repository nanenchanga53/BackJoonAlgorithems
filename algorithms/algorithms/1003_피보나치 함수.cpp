#include<iostream>
using namespace std;

int fibonacci(int n);
int zero, one;

int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main()
{
	int T, n;

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		zero = one = 0;
		cin >> n;
		fibonacci(n);
		cout << zero << ' ' << one << endl;
	}

	system("pause");
	return 0;
}