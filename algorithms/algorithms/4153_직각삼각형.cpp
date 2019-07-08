#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string isRightTri(int x, int y, int z)
{
	bool istri = false;
	istri = (z * z) == (x * x) + (y * y) ? true : false;

	return istri ? "right" : "wrong";
}

int main()
{
	int tris[4];
	while (1)
	{
		cin >> tris[0] >> tris[1] >> tris[2];
		sort(tris, tris + 3);
		if (tris[0] == 0 && tris[1] == 0 && tris[2] == 0)
			return 0;

		cout << isRightTri(tris[0],tris[1],tris[2]) << endl;
	}
	return 0;
}