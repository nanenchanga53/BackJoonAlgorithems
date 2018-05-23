#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

int readInt()
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch - '0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main()
{
	stack<int> st;

	int n, k;
	int num = 0;
	int i, j, buffer_size = 0;
	char *	buffer;
	n = readInt();

	st.push(0);

	buffer = (char *)malloc(sizeof(char) * n * 2 * 2);

	for (i = 0; i < n; i++)
	{
		k = readInt();

		while (st.top() < k)
		{
			st.push(++num);
			buffer[buffer_size] = '+';
			buffer_size++;
			buffer[buffer_size] = '\n';
			buffer_size++;

			if (num > n)
				break;
		}

		if (num > n)
			break;

		while (st.top() >= k)
		{
			buffer[buffer_size] = '-';
			buffer_size++;
			buffer[buffer_size] = '\n';
			buffer_size++;
			st.pop();
		}
	}

	if (i == n)
	{
		buffer[buffer_size - 1] = '\0';
		cout << buffer << endl;
	}
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}