#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string>
using namespace std;

int main()
{

	//하나의 string을 받아오는 것이라 아래껀 뺀다
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr), cout.tie(nullptr);
	string str;
	cin >> str;

	int result = 0;
	string temp = "";
	bool minus = false;
	for (int i = 0; i < str.size(); i++)
	{
		// 부호가 오면 계산 그리고 마지막
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (minus == true)
			{
				result -= stoi(temp);
			}
			else
			{
				result += stoi(temp);
			}
			temp = "";
			//괄호를 뺄셈 이후에 치자
			if (str[i] == '-')
			{
				minus = true;
			}
		}
		else
		{
			temp += str[i];
		}
	}
	if (temp != "")
	{
		if (minus == true)
		{
			result -= stoi(temp);
		}
		else
		{
			result += stoi(temp);
		}
		temp = "";
		
	}

	cout << result << '\n';
	return 0;
}