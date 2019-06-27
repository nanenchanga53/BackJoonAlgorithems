#include <iostream>
#include <stack>
#include<utility>
#include <queue>
using namespace std;

stack<int> hanoi[3]; //필요없지만 스택으로 쌓아보자
int num = 0;
queue<pair<int, int>> hanoiPintQueue;
void HanoiMovePrint(int from, int to)
{
	hanoi[to - 1].push(hanoi[from - 1].top());
	hanoi[from - 1].pop();
	num++;
	hanoiPintQueue.push(make_pair(from, to));
	//printf("%d %d\n", from, to); 바로출력만 하는거면 이걸 쓰자
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
	for (int i = n; i >= 1; i--) //시작하노이탑 스택쌓기
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
