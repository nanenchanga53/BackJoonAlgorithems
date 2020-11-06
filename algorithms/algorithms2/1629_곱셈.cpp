#include <stdio.h>

long long a, b, c;

long long solve(long long a, long long b, long long c)
{
        long long res;
        //������ ���� 1�϶� �׳� a�� �ѱ�
        if (b == 1)
        {
                res = a;
        }
        else
        {
                //���ڰ� �ʹ� Ŭ �� ������ ������ ���� �� ����� �ٽ� ��ħ
                long long temp = solve(a, b / 2, c);
                res = (temp * temp) % c; //�������� ���������� ���� ��������
                if (b % 2 == 1) //������ ���� Ȧ �� ���� ���
                        res = (res * a) % c;
        }
        return res;
}

int main()
{

        scanf("%lld %lld %lld", &a, &b, &c);

        printf("%lld", solve(a % c, b, c));

        return 0;
}
