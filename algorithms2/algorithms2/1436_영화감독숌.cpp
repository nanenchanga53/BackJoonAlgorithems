#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	int cnt = 0, n, i = 666;

	cin >> n;

	while (cnt < n)
	{
		string s = to_string(i);
		if (s.find("666") != string::npos)
		{
			cnt++;
			if (cnt == n)
			{
				cout << s << endl;
				break;
			}
		}
		i++;
	}

	return 0;
}