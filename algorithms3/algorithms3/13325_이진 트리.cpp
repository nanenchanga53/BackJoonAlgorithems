#include<iostream>
#include<algorithm>
using namespace std;
int k, a[1 << 21], r, i, t;
int main() 
{
	//종단 노드부터 큰쪽을 합쳐서 부모노드에게 자식중 큰값 * 2를 넘겨주면서 올라가면 된다.
	cin >> k;
	for (i = 2; i < 1 << k + 1; i++)
	{
		cin >> a[i];
	}
	
	while (i -= 2)
	{
		t = max(a[i], a[i + 1]);
		r += t;
		a[i / 2] += t;
	}
	cout << r + t;
	system("pause");
	return 0;
}