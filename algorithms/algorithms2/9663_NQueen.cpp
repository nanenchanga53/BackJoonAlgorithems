#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cmath>
using namespace std;

void Queens(int row);
bool IsOK(int c);
void PrintQueens();

int N, col[16] = { 0, };
int cnt=0;


//벡트래킹 메인
void Queens(int row)
{
	if (row == N)
	{
		cnt++;
		//PrintQueens();
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			col[row+1] = i;
			if (IsOK(row + 1))
			{
				Queens(row + 1);
			}
			else
			{
				col[row + 1] = 0;
			}
		}
	}
	col[row] = 0;
}


//퀸이 자리에 넣을 수 있는지 체크
bool IsOK(int c)
{
	for (int i = 1; i < c; i++)
	{
		if (col[i] == col[c] || abs(col[i] - col[c]) == abs(i - c))
		{
			return false;
		}
	}

	return true;
}

void PrintQueens()
{
	for (int i = 1; i <= N; i++)
	{
		printf("%d ", col[i]);
	}
	printf("\n");
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		col[1] = i;
		Queens(1);
		col[i] = 0;
	}

	printf("%d\n", cnt);
	return 0;
}