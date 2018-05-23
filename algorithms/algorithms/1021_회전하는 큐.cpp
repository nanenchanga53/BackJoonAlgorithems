#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque>
using namespace std;

deque<int> qu;
int before;
int left_move, right_move, move_cnt;

void go_right()
{
	int end_num;

	end_num = qu.back();

	qu.pop_back();
	qu.push_front(end_num);
}

void go_left()
{
	int start_num;

	start_num = qu.front();

	qu.pop_front();
	qu.push_back(start_num);
}

void pop_num(int num)
{
	deque<int>::iterator t;

	int i;

	t = qu.begin();
	for (i = 0; i < qu.size(); i++)
	{
		if (*t == num)
			break;
		t++;
	}

	if (i > qu.size() / 2)
	{
		right_move = 0;

		while (1)
		{
			t = qu.begin();
			if (*t == num)
				break;
			go_right();
			right_move++;
		}
		qu.pop_front();
		move_cnt += right_move;
	}
	else
	{
		left_move = 0;

		while (1)
		{
			t = qu.begin();
			if (*t == num)
				break;
			go_left();
			left_move++;
		}
		qu.pop_front();
		move_cnt += left_move;
	}
}

int main()
{
	int order[51];
	int m, n, k;
	move_cnt = 0;
	cin >> n;

	cin >> m;

	for (int i = 1; i <= n; i++)
		qu.push_back(i);

	before = n / 2;

	for (int i = 0; i < m; i++)
	{
		cin >> order[i];
		pop_num(order[i]);
	}

	cout << move_cnt << endl;

	system("pause");
	return 0;
}