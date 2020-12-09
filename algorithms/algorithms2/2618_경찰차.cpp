#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n, w; //���� ũ��, ����� ����

pair<int, int> conan[1002]; // �������
int dp[1001][1001]; //[1�� �������� ó���� ������ ���][2�� �������� ó���� ������ ���] 
/// <summary>
/// �̵��Ÿ� ���ϱ�
/// </summary>
int dist(pair<int, int> a, pair<int, int> b)
{
        return abs(a.first - b.first) + abs(a.second - b.second);
}

//������ �⵿�� ������ ���ϴ� dp
int ChooseCap(int x, int y)
{
        if (x == w || y == w)
                return 0;

        if (dp[x][y] != -1)
                return dp[x][y];

        int next = max(x,y) + 1;

        int dist1, dist2;
        
        //������ 1�������� �⵿�Ұ��
        if (x == 0)
                dist1 = dist({ 1,1 }, conan[next] );
        else
                dist1 = dist(conan[x], conan[next]);

        //������ 2�������� �⵿�� ���
        if (y == 0)
                dist2 = dist({ n,n }, conan[next]);
        else
                dist2 = dist(conan[y], conan[next]);

        
        dp[x][y] = min(ChooseCap(next, y) + dist1, ChooseCap(x, next) + dist2); //�������� ������ �� �ִ� 2���� ��Ȳ�� ���� ���� ����
        return dp[x][y];
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> n;
        cin >> w;        

        //��� ���� �Է�
        int x, y;
        for (int i = 1; i <= w; i++)
        {
                cin >> x >> y;
                conan[i].first = x;
                conan[i].second = y;

        }

        memset(dp, -1, sizeof(dp));
        cout << ChooseCap(0, 0) << '\n';
        
        int dist1, dist2;
        x = y = 0;

        //������ ������ �� �ִ°��� �� ª�� ���� ����
        for (int next = 1; next <= w; next++)
        {
                //������ 1�������� �⵿�Ұ��
                if (x == 0)
                        dist1 = dist({ 1,1 }, conan[next]);
                else
                        dist1 = dist(conan[x], conan[next]);

                //������ 2�������� �⵿�� ���
                if (y == 0)
                        dist2 = dist({ n,n }, conan[next]);
                else
                        dist2 = dist(conan[y], conan[next]);


                if (dp[next][y] + dist1 <= dp[x][next] + dist2)
                {
                        cout << 1 << '\n';
                        x = next;
                }
                else
                {
                        cout << 2 << '\n';
                        y = next;
                }
        }
        return 0;

}