#include <stdio.h>

int len;
int wCnt = 0;
int bCnt = 0;
int paper[129][129] = { 0, };


void CutPaper(int len, int y, int x)
{
        //�ϴ� ��� ���̰� ���� �������� ã�ƺ���
        int tmp = 0;
        for (int i = y; i < y + len; i++)
        {
                for (int j = x; j < x + len; j++)
                {
                        if (paper[i][j])
                                tmp++;
                }
        }

        //��� ���̰� �Ͼ���̸�
        if (!tmp)
        {
                wCnt++;
        }
        //��� ���̰� �Ķ����̸�
        else if (tmp == len * len)
        {
                bCnt++;
        }
        //��� ������ ���� �ʴٸ� 4���� �����ؼ� �ٽ� Ž��
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
