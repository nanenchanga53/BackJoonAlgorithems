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
			else //숫자면 (나올때까지 찾아준다.
			{
				int tmp_cnt = cur_ack;
				ack.pop();
				while (!ack.empty()) //'('나오면 break, 스택 비면 break;
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
						tmp_cnt += cur_ack; //숫자면 더해준다.
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
			else //숫자면 '['나올때까지 찾아준다.
			{
				int tmp_cnt = cur_ack;
				ack.pop();
				while (!ack.empty()) //'['나오면 break, 스택 비면 break;
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
						tmp_cnt += cur_ack; //숫자면 더해준다.
					}
				}
			}
		}
	}
	int ans_cnt = 0;
	while (!ack.empty()) // 스택에 숫자만 들어있어야 한다.
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