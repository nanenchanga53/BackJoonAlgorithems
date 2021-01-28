#include <iostream>

//�Ǻ���ġ ������ �ֱ��� ���̰� P �̸�,
//N��° �Ǻ���ġ ���� M���� ���� �������� N%P��° �Ǻ���ġ ���� M�� ���� �������� �����ϴ�.(�Ļ���ֱ�)
//M = 10^k  ��, k > 2 ���, �ֱ�� �׻� 15 �� 10^k-1
//������ 100000���� ���� �������� ���ϴ°Ŵ�
using namespace std;
const int mod = 1000000;
const int p = mod / 10 * 15;
int fibo[p] = { 0,1 };
int main() {
	long long n;
	cin >> n;
	for (int i = 2; i < p; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= mod;
	}
	cout << fibo[n%p] << '\n';
	system("pause");
	return 0;
}