#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

vector<pair<int,int>> emptyPoint;

int sdoku[10][10] = { 0, };
int emptyRows[10] = { 0, }, emptyCols[10] = { 0, }, emptySqaure[4][4] = { 0, };
bool usedNum[10] = { 0, };

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

//열 찾아보기
bool FindCols(int row, int col)
{
	bool isFind = false;

	if (emptyCols[col] == 1)
	{
		memset(usedNum, 0, sizeof(usedNum));
		for (int i = 1; i <= 9; i++)
		{
			usedNum[sdoku[i][col]] = true;
		}
		for (int i = 1; i <= 9; i++)
		{
			if (!usedNum[i])
			{
				sdoku[row][col] = i;
				//printSdoku(row, col, i);
				break;
				
			}
		}
		isFind = true;
		
	}

	return isFind;

}

//행 찾아보기
bool FindRows(int row, int col)
{
	bool isFind = false;

	if (emptyRows[col] == 1)
	{
		memset(usedNum, 0, sizeof(usedNum));
		for (int i = 1; i <= 9; i++)
		{
			usedNum[sdoku[row][i]] = true;
		}
		for (int i = 1; i <= 9; i++)
		{
			if (!usedNum[i])
			{
				sdoku[row][col] = i;
				//printSdoku(row, col, i);
				break;
			}
		}
		isFind = true;
	}

	return isFind;
}

//사각형 찾아보기
bool FindSqaure(int row, int col)
{
	bool isFind = false;
	int rowSqaure = (row - 1) / 3 + 1;
	int colSqaure = (col - 1) / 3 + 1;
	if (emptySqaure[rowSqaure][colSqaure] == 1)
	{
		memset(usedNum, 0, sizeof(usedNum));

		for (int i = rowSqaure * 3; i >= rowSqaure * 3 - 2; i--)
		{
			for (int j = colSqaure * 3; j >= colSqaure * 3 - 2; j--)
			{
				usedNum[sdoku[i][j]] = true;
			}
		}
		for (int i = 1; i <= 9; i++)
		{
			if (!usedNum[i])
			{
				sdoku[row][col] = i;
				//printSdoku(row, col, i);
				break;
			}
		}
		isFind = true;
	}
	return isFind;

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
				emptyRows[i]++;
				emptyCols[j]++;
				emptySqaure[(i - 1) / 3 + 1][(j - 1) / 3 + 1]++;
			}
		}
	}
	
	while (!emptyPoint.empty())
	{
		for (int i = 0; i < emptyPoint.size(); i++)
		{
			
			if (FindCols(emptyPoint[i].first, emptyPoint[i].second) || FindRows(emptyPoint[i].first, emptyPoint[i].second) || FindSqaure(emptyPoint[i].first, emptyPoint[i].second))
			{
				int col, row;
				row = emptyPoint[i].first;
				col = emptyPoint[i].second;
				
				emptyRows[row]--;
				emptyCols[col]--;
				emptySqaure[(row - 1) / 3 + 1][(col - 1) / 3 + 1]--;
				emptyPoint.erase(emptyPoint.begin() + i);
				i--;
			}
			
		}
	}
	printSdoku();
	return 0;
}