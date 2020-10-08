#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_N 600000
#pragma warning (disable : 4996)
using namespace std;
char str[MAX_N];
int t, n, g[MAX_N], tg[MAX_N], SA[MAX_N], r[MAX_N], LCP[MAX_N];

//풀이 : LCP를 구한다 -> String이 가질 수 있는 모든 부분물자열의 갯수에서 LCP 총합을 뺀다

//1. 어떤 부분 문자열은 어떤 접미사의 접두사이다.
//
//2. 그런데 어떤 두 접미사끼리 서로 접두사가 같은 부분이 있다면 그 부분은 부분문자열중 생김새가 같은 문자열이다.
//
//3. 따라서 총 부분문자열의 갯수에서 생김새가 같은 문자열(lcp)의 모든 갯수(lcp의 합)을 뺀다.



bool cmp(int x, int y)
{
	// 현재 보고있는 단어가 같으면 t번째 기준으로 정렬
	if (g[x] == g[y])
		return g[x + t] < g[y + t];

	// 현재 보고있는 단어가 다르다면 바로 정렬
	return g[x] < g[y];
}
void getSA(const char* str)
{
	t = 1;
	n = (int)strlen(str);    //글자의 수 배정

							 //첫 글자에 의한 그룹을 정해주는 전처리
	for (int i = 0; i < n; i++)
	{
		SA[i] = i;
		g[i] = str[i] - 'a';
	}

	//1,2,4,8... 씩 단어의 길이보다 작은 경우를 탐색
	while (t <= n)
	{
		g[n] = -1;
		sort(SA, SA + n, cmp);    //그룹에 의한 정렬
		tg[SA[0]] = 0;    //다음 그룹을 할당하기 위하여 tempgroup의 첫번째 번호 배정

						  //다음 그룹 배정 
		for (int i = 1; i < n; i++)
		{
			//그룹이 다를 경우 다음 그룹 번호 할당
			if (cmp(SA[i - 1], SA[i]))
				tg[SA[i]] = tg[SA[i - 1]] + 1;

			//그룹이 같을 경우 같은 그룹 번호 할당
			else
				tg[SA[i]] = tg[SA[i - 1]];
		}

		//새로운 그룹 할당
		for (int i = 0; i < n; i++)
			g[i] = tg[i];

		t <<= 1; // t *= 2;
	}
}
int main()
{
	scanf("%s", &str);
	getSA(str);

	// r 배열에는 접미사 배열 순서가 들어간다.
	for (int i = 0; i < n; i++)
		r[SA[i]] = i;

	int len = 0;

	for (int i = 0; i < n; i++)
	{
		int k = r[i];
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

	int LCPSum = 0;
	int StringCnt = 0;
	for (int i = 1; i < n; i++)
	{
		LCPSum += LCP[i];
		StringCnt += i;
	}

	StringCnt += n;

	printf("%d\n", (StringCnt - LCPSum));

	system("pause");

	return 0;
}