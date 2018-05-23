#include<iostream>
using namespace std;
int main()
{
	int guest_out, guest_in;
	int guest_count, max;
	guest_count = 0;
	max = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> guest_out >> guest_in;
		guest_count += guest_in;
		guest_count -= guest_out;
		if (max < guest_count)
		{
			max = guest_count;
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}