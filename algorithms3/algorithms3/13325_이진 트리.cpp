#include<iostream>
#include<algorithm>
using namespace std;
int k, a[1 << 21], r, i, t;
int main() 
{
	//���� ������ ū���� ���ļ� �θ��忡�� �ڽ��� ū�� * 2�� �Ѱ��ָ鼭 �ö󰡸� �ȴ�.
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