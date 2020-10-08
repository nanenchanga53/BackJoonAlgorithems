#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<char, char>> alpa[26];

void preOrder(char root)
{
	char left = alpa[root - 'A'].front().first;
	char right = alpa[root - 'A'].front().second;

	cout << root;
	if (left != '.') preOrder(left);
	if (right != '.') preOrder(right);
}

void inOrder(char root)
{
	char left = alpa[root - 'A'].front().first;
	char right = alpa[root - 'A'].front().second;

	
	if (left != '.') inOrder(left);
	cout << root;
	if (right != '.') inOrder(right);
}

void postOrder(char root)
{
	char left = alpa[root - 'A'].front().first;
	char right = alpa[root - 'A'].front().second;

	
	if (left != '.') postOrder(left);
	if (right != '.') postOrder(right);
	cout << root;
}

int main()
{
	int n;
	cin >> n;
	char root, left, right;

	for (int i = 0; i < n; i++)
	{
		cin >> root >> left >> right;
		if (root != '.')
			alpa[root - 'A'].push_back(make_pair(left, right));
		
	}

	preOrder('A');
	cout << '\n';
	inOrder('A');
	cout << '\n';
	postOrder('A');
	cout << '\n';

	system("pause");
	return 0;
}