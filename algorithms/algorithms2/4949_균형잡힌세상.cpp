#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
#include<stack>
#include <string>
using namespace std;


int main()
{
	string str;
	while (1)
	{
		int flag = false;
		getline(cin, str);
		if (str == ".")
		{
			break;
		}
		else
		{
			stack<char> brankets;
			int i;
			for (i = 0; i < str.size(); i++)
			{
				if (str[i] == '(')
				{
					brankets.push('(');
				}
				else if (str[i] == ')')
				{
					if (brankets.empty())
						break;
										
					if (brankets.top() == '(')
					{
						brankets.pop();
						flag = true;
					}
					else
					{
						break;
					}
				}
				else if (str[i] == '[')
				{
					brankets.push('[');
				}
				else if (str[i] == ']')
				{
					if (brankets.empty())
						break;

					if (brankets.top() == '[')
					{
						brankets.pop();
						flag = true;
					}
					else
					{
						break;
					}
				}
			}
			if (brankets.size() > 0 && i < str.size())
				cout << "no" << '\n';
			else if (brankets.size() == 0 && i < str.size())
				cout << "no" << '\n';
			else if (brankets.size() > 0 && i == str.size())
				cout << "no" << '\n';
			else if(brankets.size() == 0 && i == str.size())
				cout << "yes" << '\n';
		}
	}

	return 0;
}