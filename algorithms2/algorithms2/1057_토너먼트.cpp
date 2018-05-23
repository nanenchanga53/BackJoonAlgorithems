#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int n, kim, im;
	int cnt = 1;
	cin >> n >> kim >> im;

	while (1)
	{
		if (abs(kim - im) == 1 && (kim + 1) / 2 == (im + 1) / 2)
		{
			cout << cnt << endl;
			break;
		}
		kim = (kim + 1) / 2;
		im = (im + 1) / 2;
		cnt++;
	}

	

	system("pause");
	return 0;
}