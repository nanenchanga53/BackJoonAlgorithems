#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string>
using namespace std;

int main()
{

	//�ϳ��� string�� �޾ƿ��� ���̶� �Ʒ��� ����
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr), cout.tie(nullptr);
	string str;
	cin >> str;

	int result = 0;
	string temp = "";
	bool minus = false;
	for (int i = 0; i < str.size(); i++)
	{
		// ��ȣ�� ���� ��� �׸��� ������
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
			//��ȣ�� ���� ���Ŀ� ġ��
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