#include<iostream>
#include<algorithm>
#include<cstring>        //memset

using namespace std;

int n,m;

int memory[100];
int cost[100];
//cache[i][j]는 i위치부터 j비용으로 만들수 있는 최대 메모리 크기
int cache[100][10001];

int calc_memory(const int& now, const int& maxCost) 
{
        if (now >= n)
                return 0;

        //동적(메모제이션) 활용
        int &ret = cache[now][maxCost]; //여기 계속 새로 생성하면 시간초과난다 그래서 &을 붙이자

        //이미 탐색이 완료된 경우
        if (ret != -1) return ret;

        //현재 앱을 활성화
        ret = calc_memory(now + 1, maxCost);

        //현재 앱을 비활성화 시키는 경우
        if (cost[now] <= maxCost)
        {
                //현재 앱을 비활성화 시키지 않은 경우와 비교하여 더 큰 메모리를 선택
                ret = max(ret, memory[now] + calc_memory(now + 1, maxCost - cost[now]));
        }

        return ret;
}

int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> n >> m;

        for (int i = 0; i < n; i++)
                cin >> memory[i];
        for (int i = 0; i < n; i++)
                cin >> cost[i];

        //동적(메모이제이션)을 활용하기 위해 초기화
        memset(cache, -1, sizeof(cache));

        int ret = 0;

        //가능한 최대 코스트는 10000까지 탐색을 진행하도록 하자. (100 * 100 개의 코스트가 올 수 있다 물론 0도)
        for (int i = 0; i < 10001; i++) 
        {
                ret = calc_memory(0, i);
                if (ret >= m) 
                {
                        cout << i;
                        break;
                }
        }

        return 0;
}
