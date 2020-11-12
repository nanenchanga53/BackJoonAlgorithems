#include<iostream>
#include<algorithm>
#include<cstring>        //memset

using namespace std;

// 테스트케이스, 가로길이, 세로길이, 양배추가 심어진 위치 개수
int t,m, n, k,cabbage[54][54];

int wormCnt=0;
void WormHome(int x, int y)
{
        cabbage[x][y] = 2;
        if (cabbage[x][y + 1] == 1)
        {
                WormHome(x, y + 1);
        }

        if (cabbage[x + 1][y] == 1)
        {
                WormHome(x + 1, y);
        }

        if (cabbage[x][y - 1] == 1)
        {
                WormHome(x, y - 1);
        }

        if (cabbage[x - 1][y] == 1)
        {
                WormHome(x - 1, y);
        }
        
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> t;
        
        int x, y;

        for (int tcase = 0; tcase < t; tcase++)
        {
                memset(cabbage, 0, sizeof(cabbage));
                cin >> m >> n >> k;
                wormCnt = 0;

                for (int i = 0; i < k; i++)
                {
                        cin >> x >> y;
                        cabbage[y+1][x+1] = 1;
                }

                for (int i = 1; i <= n; i++)
                {
                        for (int j = 1; j <= m; j++)
                        {
                                if (cabbage[i][j] == 1)
                                {
                                        wormCnt++;
                                        WormHome(i, j);
                                }
                        }
                }
                cout << wormCnt << '\n';
        }

        return 0;
}
