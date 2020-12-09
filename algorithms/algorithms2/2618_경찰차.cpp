#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n, w; //맵의 크기, 사건의 개수

pair<int, int> conan[1002]; // 사건현장
int dp[1001][1001]; //[1번 경찰차가 처리한 마지막 사건][2번 경찰차가 처리한 마지막 사건] 
/// <summary>
/// 이동거리 구하기
/// </summary>
int dist(pair<int, int> a, pair<int, int> b)
{
        return abs(a.first - b.first) + abs(a.second - b.second);
}

//다음에 출동할 결찰을 정하는 dp
int ChooseCap(int x, int y)
{
        if (x == w || y == w)
                return 0;

        if (dp[x][y] != -1)
                return dp[x][y];

        int next = max(x,y) + 1;

        int dist1, dist2;
        
        //다음에 1번차량이 출동할경우
        if (x == 0)
                dist1 = dist({ 1,1 }, conan[next] );
        else
                dist1 = dist(conan[x], conan[next]);

        //다음에 2번차량이 출동할 경우
        if (y == 0)
                dist2 = dist({ n,n }, conan[next]);
        else
                dist2 = dist(conan[y], conan[next]);

        
        dp[x][y] = min(ChooseCap(next, y) + dist1, ChooseCap(x, next) + dist2); //다음번에 선택할 수 있는 2가지 상황중 작은 것을 고른다
        return dp[x][y];
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> n;
        cin >> w;        

        //사건 현장 입력
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

        //다음에 선택할 수 있는것중 더 짧은 것을 고른다
        for (int next = 1; next <= w; next++)
        {
                //다음에 1번차량이 출동할경우
                if (x == 0)
                        dist1 = dist({ 1,1 }, conan[next]);
                else
                        dist1 = dist(conan[x], conan[next]);

                //다음에 2번차량이 출동할 경우
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