#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;

	for (int i = l; i <= 100; i++) {
		if (i % 2 == 0) {
			if (n%i == (i >> 1) && (n / i + 1) - (i >> 1) >= 0) {
				for (int j = (n / i + 1) - (i >> 1); j<(n / i + 1) + (i >> 1); j++) {
					cout << j << " ";
				}
				return 0;
			}
		}
		else {
			if (n%i == 0 && (n / i) - (i >> 1) >= 0) {
				for (int j = (n / i) - (i >> 1); j <= (n / i) + (i >> 1); j++) {
					cout << j << " ";
				}
				return 0;
			}
		}
	}
	cout << -1 << endl;
	system("pause");
	return 0;
}