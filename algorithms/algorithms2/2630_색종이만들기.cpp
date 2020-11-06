#include <stdio.h>

int len;
int wCnt = 0;
int bCnt = 0;
int paper[129][129] = { 0, };


void CutPaper(int len, int y, int x)
{
        //일단 모든 종이가 같은 색깔인지 찾아본다
        int tmp = 0;
        for (int i = y; i < y + len; i++)
        {
                for (int j = x; j < x + len; j++)
                {
                        if (paper[i][j])
                                tmp++;
                }
        }

        //모든 종이가 하얀색이면
        if (!tmp)
        {
                wCnt++;
        }
        //모든 종이가 파란색이면
        else if (tmp == len * len)
        {
                bCnt++;
        }
        //모든 색깔이 같지 않다면 4개로 분할해서 다시 탐색
        else
        {
                CutPaper(len / 2, y, x);
                CutPaper(len / 2, y, x + (len / 2));
                CutPaper(len / 2, y + (len / 2), x);
                CutPaper(len / 2, y + (len / 2), x + (len / 2));
        }

}



int main()
{
        scanf("%d", &len);

        for (int i = 1; i <= len; i++)
        {
                for (int j = 1; j <= len; j++)
                {
                        scanf("%d", &paper[i][j]);
                }
        }

        CutPaper(len, 1, 1);

        printf("%d\n%d", wCnt, bCnt);

        return 0;
}
