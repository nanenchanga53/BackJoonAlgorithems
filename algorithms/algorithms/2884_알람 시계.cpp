#include<iostream>
using namespace std;
int main()
{
	int H, M;//입력
	int resH, resM;//출력

	cin >> H >> M;

	resH = H;
	resM = M;
	resM = resM - 45;
	if (resM < 0)
	{
		resH--;
		resM = resM + 60;

		if (resH < 0)
			resH = 23;
	}

	cout << resH << ' ' << resM << endl;
	return 0;
}