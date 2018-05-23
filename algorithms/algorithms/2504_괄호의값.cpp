#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

char str[32];

int main()
{
	stack<int> ack;
	cin >> str;
	int str_len = strlen(str);
	for (int i = 0; i < str_len; i++)
	{
		char cur_str = str[i];
		if (cur_str == '(') {
			ack.push('(' * (-1));
		}
		else if (cur_str == '[') {
			ack.push('[' * (-1));
		}
		else if (cur_str == ')')
		{
			if (ack.empty())
			{
				printf("0\n");
				return 0;
			}
			char cur_ack = ack.top();
			if (cur_ack == '[' * (-1))
			{
				printf("0\n");
				return 0;
			}
			if (cur_ack == '(' * (-1)) {
				ack.pop();
				ack.push(2);
			}
			else //���ڸ� (���ö����� ã���ش�.
			{
				int tmp_cnt = cur_ack;
				ack.pop();
				while (!ack.empty()) //'('������ break, ���� ��� break;
				{
					cur_ack = ack.top();
					ack.pop();
					if (cur_ack == '(' * (-1))
					{
						ack.push(tmp_cnt * 2);
						break;
					}
					else if (cur_ack == '[' * (-1))
					{
						printf("0\n");
						return 0;
					}
					else
					{
						tmp_cnt += cur_ack; //���ڸ� �����ش�.
					}
				}
			}
		}
		else // (cur_str == ']')
		{
			if (ack.empty()) {
				printf("0\n");
				return 0;
			}
			char cur_ack = ack.top();
			if (cur_ack == '(' * (-1)) {
				printf("0\n");
				return 0;
			}
			if (cur_ack == '[' * (-1)) {
				ack.pop();
				ack.push(3);
			}
			else //���ڸ� '['���ö����� ã���ش�.
			{
				int tmp_cnt = cur_ack;
				ack.pop();
				while (!ack.empty()) //'['������ break, ���� ��� break;
				{
					cur_ack = ack.top();
					ack.pop();
					if (cur_ack == '[' * (-1))
					{
						ack.push(tmp_cnt * 3);
						break;
					}
					else if (cur_ack == '(' * (-1))
					{
						printf("0\n");
						return 0;
					}
					else
					{
						tmp_cnt += cur_ack; //���ڸ� �����ش�.
					}
				}
			}
		}
	}
	int ans_cnt = 0;
	while (!ack.empty()) // ���ÿ� ���ڸ� ����־�� �Ѵ�.
	{
		int cur_ack = ack.top();
		ack.pop();
		if (cur_ack < 0)
		{
			printf("0\n");
			return 0;
		}
		ans_cnt += cur_ack;
	}
	cout << ans_cnt << endl;
	system("pause");
}