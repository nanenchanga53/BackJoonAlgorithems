#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct move_items
{
	long long max_move;
	long long count_move;
	long long speed;
};

vector<move_items> vecmove;

void back()
{
	long long i;
	move_items speed;
	for (i = 0; i < 50000; i++)
	{
		speed.max_move = i * i;
		speed.count_move = 2 * i - 1;
		speed.speed = i;
		vecmove.push_back(speed);
	}
}

int main()
{
	back();

	long long T, i;
	cin >> T;

	for (long long t = 0; t < T; t++)
	{
		long long x, y;
		cin >> x >> y;

		long long len, cnt, down;

		long long after_len;

		len = y - x;
		down = 0;
		for (i = 1;; i++)
		{
			if (vecmove[i].max_move > len)
				break;
		}

		i--;

		after_len = len - vecmove[i].max_move;

		if (after_len % vecmove[i].speed == 0)
			down = after_len / vecmove[i].speed;
		else
			down = after_len / vecmove[i].speed + 1;

		cnt = vecmove[i].count_move + down;

		cout << cnt << endl;
	}
	system("pause");
	return 0;
}