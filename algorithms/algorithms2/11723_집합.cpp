#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int M;

	long bitMask = 0;
	string f;
	int num;
	int changeBit;

	cin >> M;

	while (M--)
	{
		cin >> f;
		if (f == "add")
		{
			cin >> num;
			changeBit = 1 << (num - 1);
			bitMask = bitMask | changeBit;
		}
		else if (f == "remove")
		{
			cin >> num;
			changeBit = 1 << (num - 1);
			bitMask = bitMask & ~changeBit;
		}
		else if (f == "check")
		{
			cin >> num;
			changeBit = 1 << (num - 1);
			if (bitMask & changeBit)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (f == "toggle")
		{
			cin >> num;
			changeBit = 1 << (num - 1);
			if (bitMask & changeBit)
				bitMask = bitMask & ~changeBit;
			else
				bitMask = bitMask | changeBit;
		}
		else if (f == "all")
		{
			bitMask = (1 << 20) - 1;
		}
		else if (f == "empty")
		{
			bitMask = 0;
		}
	}

	return 0;
}