#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string reverse(const string& input)
{
	string temp(input);
	reverse(temp.begin(), temp.end());
	return temp;
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	str1 = reverse(str1);
	str2 = reverse(str2);

	int value1 = atoi(str1.c_str());
	int value2 = atoi(str2.c_str());
	if (value1 > value2)
		cout << value1 << endl;
	else
		cout << value2 << endl;

	return 0;
}