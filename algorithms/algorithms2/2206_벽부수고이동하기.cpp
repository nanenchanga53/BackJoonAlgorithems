#include<iostream>
#include<algorithm>
#include<queue>
#define MAXNUM 1000
using namespace std;

char insert;
int n, m;
int map[1002][1002] = { 0, };
int chk[1002][1002][2] = { 0, };

struct point 
{
        int row, col, flag;
};

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        queue<point> que;

        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= m; j++)
                {
                        cin >> insert;
                        map[i][j] = insert - '0';
                }
                
        }

        int wy[4] = { -1, 0, 1, 0 }; //왼 위 오 아
        int wx[4] = { 0, -1, 0, 1 };
        
        que.push({1,1,0});
        chk[1][1][0] = 1;
        chk[n][m][0] = -1;
        chk[n][m][1] = -1;

        int x, y, f = 0;

        while (!que.empty())
        {
                x = que.front().row;
                y = que.front().col;
                f = que.front().flag;
                que.pop();

                if (x == n && y == m)
                        break;

                for (int i = 0; i < 4; i++)
                {
                        int moveX = x + wx[i];
                        int moveY = y + wy[i];

                        if (moveX < 1 || moveY < 1 || moveX > n || moveY > m) //범위를 넘어가지 않도록
                                continue;
                        if (chk[moveX][moveY][f] > 0) //이미 방문한곳
                                continue;

                        if (map[moveX][moveY] == 0)
                        {
                                chk[moveX][moveY][f] = chk[x][y][f] + 1;
                                que.push({ moveX,moveY,f });
                        }
                        if (map[moveX][moveY] == 1 && f == 0)
                        {
                                chk[moveX][moveY][1] = chk[x][y][f] + 1;
                                que.push({ moveX,moveY,1 });
                        }
                }
        }

        if (n == 1 && m == 1)
                cout << 1 << '\n';
        else
                cout << chk[n][m][f] << '\n';

        return 0;
}
