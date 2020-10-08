#include<iostream>
#define MAX 987654321
#define Max(a,b) (a > b ? a : b)

using namespace std;

int arr[100001], DP[100001], N;
int Solve(int i)
{
	if (DP[i])
		return DP[i];
	if (i == N) 
		return arr[i];

	return DP[i] = Max(arr[i], arr[i] + Solve(i + 1));
}
int main()
{
	int ans = -MAX;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 1; i <= N; i++)
		ans = Max(ans, Solve(i));
	cout << ans << endl;
}