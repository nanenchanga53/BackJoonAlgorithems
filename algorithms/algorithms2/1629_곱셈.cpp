#include <stdio.h>

long long a, b, c;

long long solve(long long a, long long b, long long c)
{
        long long res;
        //나누는 수가 1일때 그냥 a를 넘김
        if (b == 1)
        {
                res = a;
        }
        else
        {
                //숫자가 너무 클 수 있으니 나누는 절반 씩 나누어서 다시 함침
                long long temp = solve(a, b / 2, c);
                res = (temp * temp) % c; //절반으로 나누었던걸 나시 나누어줌
                if (b % 2 == 1) //나누는 수가 홀 수 였을 경우
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
