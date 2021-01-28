#include <iostream>

//피보나치 수열은 주기의 길이가 P 이면,
//N번째 피보나치 수를 M으로 나눈 나머지는 N%P번째 피보나치 수를 M을 나눈 나머지와 같습니다.(파사노주기)
//M = 10^k  때, k > 2 라면, 주기는 항상 15 × 10^k-1
//문제는 100000으로 나눈 나머지를 구하는거니
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