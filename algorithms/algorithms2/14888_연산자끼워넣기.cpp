#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N;
int nums[101] = { 0, };
int operations[5] = { 0, };
int maxNum = -1e9, minNum = 1e9;


void BackTraking(vector<char>& ops, int remainPlus, int remainMin, int remainMul,int remainDiv)
{
	if (!(remainPlus | remainMin | remainMul | remainDiv)) //남은 연산자가 없다
	{
		int res = nums[0];

		for (int i = 0; i < N - 1; i++)
		{
			switch (ops[i])
			{
			case '+':
				res += nums[i + 1];
				break;
			case '-':
				res -= nums[i + 1];
				break;
			case '*':
				res *= nums[i + 1];
				break;
			case '/':
				res /= nums[i + 1];
				break;
			}
		}

		minNum = min(minNum, res);
		maxNum = max(maxNum, res);
		return;
	}

	if (remainPlus)
	{
		ops.push_back('+');
		BackTraking(ops, remainPlus - 1, remainMin, remainMul, remainDiv);
		ops.pop_back();
	}

	if (remainMin)
	{
		ops.push_back('-');
		BackTraking(ops, remainPlus, remainMin - 1 , remainMul, remainDiv);
		ops.pop_back();
	}

	if (remainMul)
	{
		ops.push_back('*');
		BackTraking(ops, remainPlus, remainMin, remainMul - 1, remainDiv);
		ops.pop_back();
	}

	if (remainDiv)
	{
		ops.push_back('/');
		BackTraking(ops, remainPlus, remainMin, remainMul, remainDiv - 1);
		ops.pop_back();
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> operations[i];
	}

	vector<char> op;

	BackTraking(op,operations[0],operations[1],operations[2],operations[3]);

	cout << maxNum << '\n' << minNum;

	return 0;
}