#include<iostream>
#include<algorithm>
using namespace std;

int num_arr[10][10] = { 0, };

int find_decrease_num,sum=0;
int i, j, k;

void First_Line()
{
	for (i = 0; i < 10; i++) num_arr[0][i] = 1;

	for (i = 1; i < 10; i++)
	{
		for (j = i; j < 10; j++)
		{
			if (j == i)
				num_arr[i][j] = 1;
			else
				for (k = i - 1; k < j; k++)
					num_arr[i][j] += num_arr[i - 1][k];
		}
	}
}

int main()
{
	
	long long start_num;
	long long digit;
	bool isFindRange = false;

	cin >> find_decrease_num;
	if (find_decrease_num == 0)
	{
		cout << 0;
		return 0;
	}

	First_Line();

	for (i = 0; i < 10 && (!isFindRange); i++) {
		for (j = i; j < 10 && (!isFindRange); j++) {
			if ((sum + num_arr[i][j]) > find_decrease_num) {
				isFindRange = 1;
			}
			else {
				digit = i + 1;
				start_num = j + 1;
				sum += num_arr[i][j];
			}
		}
	}

	system("pause");
	return 0;
}