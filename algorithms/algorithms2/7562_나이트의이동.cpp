#include <iostream>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

int T,l,ans;
bool board[301][301];
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
queue<tuple<int, int,int>> qu;

pair<int, int> start, goal;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> T;
        while (T--)
        {
                cin >> l;

                qu = queue<tuple<int, int, int>>();
                for (int i = 0; i < l; i++)
                {
                        for (int j = 0; j < l; j++)
                        {
                                board[i][j] = false;
                        }
                }

                cin >> start.first >> start.second; // ½ÃÀÛÁÂÇ¥
                cin >> goal.first >> goal.second; // µµÂøÁÂÇ¥

                qu.push({ start.first, start.second , 0 });
                board[start.first][start.second] = true; // ½ÃÀÛÁÂÇ¥ ¹æ¹®

                while (!qu.empty())
                {
                        tuple<int, int, int> now = make_tuple(get<0>(qu.front()) ,get<1>(qu.front()), get<2>(qu.front()));
                        qu.pop();

                        if (get<0>(now) == goal.first && get<1>(now) == goal.second)
                        {
                                ans = get<2>(now);
                                break;
                        }

                        for (int i = 0; i < 8; i++)
                        {
                                pair<int, int> next = make_pair(get<0>(now) + dx[i], get<1>(now) + dy[i]);

                                if (next.first >= 0 && next.first < l && next.second >= 0 && next.second < l)
                                {
                                        if (!board[next.first][next.second])
                                        {
                                                board[next.first][next.second] = true;
                                                qu.push(make_tuple(next.first, next.second, get<2>(now) + 1));
                                        }
                                }

                        }
                }
                cout << ans << '\n';
        }

        
        return 0;

}