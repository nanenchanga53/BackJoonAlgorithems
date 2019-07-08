#include<iostream>
#define min(a,b) (a>b?b:a)
#define calc(a,b) (2*b<a?b:a-b)
using namespace std;


int main()
{
	int x, y, w, h,res;
	cin >> x >> y >> w >> h;
	res = min(calc(w, x), calc(h, y));
	cout << res << endl;
	
	return 0;
}