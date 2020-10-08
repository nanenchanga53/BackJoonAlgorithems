#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	int cnt;
	cin >> n;
	cnt = 0;

	while (n > 0)
	{
		if (n & 1) 
			cnt++;
		n >>= 1;
	}

	
	cout << cnt << endl;
	
	system("pause");
	return 0;
}