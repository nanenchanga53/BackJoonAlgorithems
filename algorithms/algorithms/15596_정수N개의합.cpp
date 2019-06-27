#include <vector>
#include <iostream>
using namespace std;
long long sum(std::vector<int> &a)
{
	long long ans = 0;
	while(!a.empty())
	{
		long long num;
		num = a.back();
		a.pop_back();
		ans += num;
	}
	return ans;
}
//제출은 위쪽만 내면되는 희한한 문제였다.
int main()
{
	vector<int> a{1,2,3,4};

	cout << sum(a) << endl;
}