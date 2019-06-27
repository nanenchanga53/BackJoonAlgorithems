#include <iostream>
#include <stack>
#include<utility>
#include <queue>
using namespace std;

stack<int> hanoi[3]; //�ʿ������ �������� �׾ƺ���
int num = 0;
queue<pair<int, int>> hanoiPintQueue;
void HanoiMovePrint(int from, int to)
{
	hanoi[to - 1].push(hanoi[from - 1].top());
	hanoi[from - 1].pop();
	num++;
	hanoiPintQueue.push(make_pair(from, to));
	//printf("%d %d\n", from, to); �ٷ���¸� �ϴ°Ÿ� �̰� ����
}

void HanoiMove(int n,int from, int by, int to)
{
	if (n == 1)
	{
		HanoiMovePrint(from, to);
	}
	else
	{
		HanoiMove(n - 1, from, to, by);
		HanoiMovePrint(from, to);
		HanoiMove(n - 1, by, from, to);
	}
}

int main()
{
	int n = 0;
	
	cin >> n;
	for (int i = n; i >= 1; i--) //�����ϳ���ž ���ýױ�
	{
		hanoi[0].push(i);
	}

	HanoiMove(n, 1, 2, 3);

	printf("%d\n", num);
	while (!hanoiPintQueue.empty())
	{
		printf("%d %d\n", hanoiPintQueue.front().first,hanoiPintQueue.front().second);
		hanoiPintQueue.pop();
	}

	return 0;
}
