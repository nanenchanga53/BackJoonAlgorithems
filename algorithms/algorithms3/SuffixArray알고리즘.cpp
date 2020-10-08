#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_N 600000
using namespace std;

#pragma warning (disable : 4996)

/*
str :: ���ڿ��� �� �迭
t :: �ܾ��� ��ġ�� ���� ����
n :: str�� ����
g :: �׷�
tg :: �� �׷�
SA :: Suffix Array
Rank ���������� �� ��° ���̻����� Rank[pos[i]] = i
Pos ���ڿ� s�� ���̻� �迭
lcp(x,y) ���ڿ� s ������ �ִ� ���� ���λ��� ����
*/

char str[MAX_N];
int t, n, g[MAX_N], tg[MAX_N], SA[MAX_N], RANK[MAX_N], LCP[MAX_N];


bool cmp(int x, int y)
{
	// �׷� ��ȣ�� ������
	if (g[x] == g[y])
		return g[x + t] < g[y + t];

	// �׷� ��ȣ�� �ٸ���
	return g[x] < g[y];
}

void getSA(const char* str)
{
	t = 1;
	n = (int)strlen(str);    //������ �� ����

							 //ù ���ڿ� ���� �׷��� �����ִ� ��ó��
	for (int i = 0; i < n; i++)
	{
		SA[i] = i;
		g[i] = str[i] - 'a';
	}

	//1,2,4,8... �� �ܾ��� ���̺��� ���� ��츦 Ž��
	while (t <= n)
	{
		//    g[n] = -1;
		sort(SA, SA + n, cmp);    //�׷쿡 ���� ����
		tg[SA[0]] = 0;    //���� �׷��� �Ҵ��ϱ� ���Ͽ� tempgroup�� ù��° ��ȣ ����

						  //���� �׷� ���� 
		for (int i = 1; i < n; i++)
		{
			//�׷��� �ٸ� ��� ���� �׷� ��ȣ �Ҵ�
			if (cmp(SA[i - 1], SA[i]))
				tg[SA[i]] = tg[SA[i - 1]] + 1;

			//�׷��� ���� ��� ���� �׷� ��ȣ �Ҵ�
			else
				tg[SA[i]] = tg[SA[i - 1]];
		}

		//���ο� �׷� �Ҵ�
		for (int i = 0; i < n; i++)
			g[i] = tg[i];

		t <<= 1; // t *= 2;
	}
}


int main()
{
	scanf("%s", &str);
	getSA(str);

	// RANK �迭���� ���̻� �迭 ������ ����.
	for (int i = 0; i < n; i++)
		RANK[SA[i]] = i;

	int len = 0;

	for (int i = 0; i < n; i++)
	{
		int k = RANK[i];
		if (k)
		{
			int j = SA[k - 1];

			while (str[j + len] == str[i + len])
				len++;

			LCP[k] = len;

			if (len)
				len--;
		}
	}

	printf("\n[Suffix Array]\n");

	for (int i = 0; i < n; i++)
		printf("%s\n", str + SA[i]);

	printf("\n[Suffix Array Order]\n");
	for (int i = 0; i < n; i++)
		printf("%d ", SA[i] + 1);

	printf("\n\n[LCP]\n");
	for (int i = 0; i < n; i++)
	{
		if (!i)
			printf("x ");
		else
			printf("%d ", LCP[i]);
	}

	printf("\n\n");

	system("pause");

	return 0;
}
