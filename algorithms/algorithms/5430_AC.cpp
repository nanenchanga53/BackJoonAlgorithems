#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;

deque<int> qu;

int T;
char order[100001] = { 0, };
int nums;
char numbers[300001] = { 0, };
bool pop_deque(bool side)
{
	if (qu.empty())
	{
		cout << "error" << endl;
		return true;
	}

	if (side == false)
	{
		qu.pop_front();
	}
	else
	{
		qu.pop_back();
	}

	return false;
}

void inserting_num()
{
	int len = strlen(numbers);
	int num = 0;
	if (len == 2)
		return;
	for (int i = 1; i < len; i++)
	{
		if (numbers[i] >= '0' && numbers[i] <= '9')
		{
			num *= 10;
			num += numbers[i] - '0';
		}
		else
		{
			qu.push_back(num);
			num = 0;
		}
	}
}

void printing_nums(bool side)
{
	int t;
	bool first = true;
	cout << '[';
	if (side == false)
	{
		while (!qu.empty())
		{
			if (first)
				first = false;
			else
				cout << ',';
			cout << qu.front();
			qu.pop_front();
		}
	}
	else
	{
		while (!qu.empty())
		{
			if (first)
				first = false;
			else
				cout << ',';
			cout << qu.back();
			qu.pop_back();
		}
	}
	cout << ']' << endl;
}

int main()
{
	bool flag = false;
	int len;
	int n;
	bool empty = false;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		flag = false;
		empty = false;
		qu.clear();
		cin >> order;
		len = strlen(order);

		cin >> n;

		cin >> numbers;

		inserting_num();

		for (int i = 0; i < len; i++)
		{
			if (order[i] == 'R')
			{
				flag = !flag;
			}
			else if (order[i] == 'D')
			{
				empty = pop_deque(flag);
			}
			if (empty)
				break;
		}

		if (!empty)
			printing_nums(flag);
	}

	system("pause");
	return 0;
}