#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define squarePoint(a,b) (3 * ((a-1) / 3)) + ((b-1) / 3) + 1
using namespace std;

vector<pair<int,int>> emptyPoint;

int sdoku[10][10] = { 0, };
bool usedRows[10][10] = { 0, }, usedCols[10][10] = { 0, }, usedSquare[10][10] = { 0, };
void printSdoku(int row, int col, int num)
{
	printf("---------------\n");
	printf("%d %d %d\n", row, col, num);
	printf("---------------\n");
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%d ", sdoku[i][j]);
		}
		printf("\n");
	}
}

void printSdoku()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf("%d ", sdoku[i][j]);
		}
		printf("\n");
	}
}

void SolveSdoku()
{
	if (emptyPoint.empty())
	{
		printSdoku();
		exit(0);
	}
	else
	{
		pair<int, int> nowPoint = emptyPoint.back();

		for (int k = 1; k <= 9; k++)
		{
			if (!usedRows[nowPoint.first][k] && !usedCols[nowPoint.second][k] && !usedSquare[squarePoint(nowPoint.first, nowPoint.second)][k])
			{
				sdoku[nowPoint.first][nowPoint.second] = k;
				usedRows[nowPoint.first][k] = true;
				usedCols[nowPoint.second][k] = true;
				usedSquare[squarePoint(nowPoint.first, nowPoint.second)][k] = true;
				emptyPoint.pop_back();
				SolveSdoku();				
				sdoku[nowPoint.first][nowPoint.second] = k;
				usedRows[nowPoint.first][k] = false;
				usedCols[nowPoint.second][k] = false;
				usedSquare[squarePoint(nowPoint.first, nowPoint.second)][k] = false;
				emptyPoint.push_back(nowPoint);

			}
		}
	}
	
}

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			scanf("%d", &sdoku[i][j]);
			if (sdoku[i][j] == 0)
			{			
				emptyPoint.push_back(pair<int, int>(i, j));
				
			}
			else if(sdoku[i][j] != 0)
			{
				usedRows[i][sdoku[i][j]] = true;
				usedCols[j][sdoku[i][j]] = true;
				usedSquare[squarePoint(i, j)][sdoku[i][j]] = true;
			}
		}
	}
	
	SolveSdoku();
	return 0;
}