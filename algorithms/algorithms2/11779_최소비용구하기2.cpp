#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
#include <climits>
using namespace std;

struct BusInfo
{
        int now;
        int value;
};

bool operator < (BusInfo t, BusInfo u)
{

        return t.value > u.value;
}

int n; //도시의개수
int m; //버스의 개수
vector<BusInfo> bus[1001]; //버스길 정보
int dist[1001]; //경로 최소값
int before[1001]; //이전 선택경로
priority_queue<BusInfo> heap;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> n;
        cin >> m;

        int s, g, c; //입력 버스정보
        for (int i = 0; i < m; i++)
        {
                cin >> s >> g >> c;
                bus[s].push_back({ g,c });
        }

        int start, goal; //시작위치 목표위치
        cin >> start >> goal;

        for (int i = 0; i <= n; i++)
                dist[i] = INT_MAX;

        heap.push({ start,0 });

        int t;

        while (!heap.empty())
        {
                BusInfo topInfo;
                topInfo = heap.top();
                heap.pop();

                if (dist[topInfo.now] < topInfo.value)
                {
                        continue;
                }

                for (int i = 0; i < bus[topInfo.now].size(); i++)
                {
                        int there = bus[topInfo.now][i].now;
                        int nextDist = topInfo.value + bus[topInfo.now][i].value;

                        if (dist[there] > nextDist)
                        {
                                dist[there] = nextDist;
                                before[there] = topInfo.now;
                                heap.push({ there,nextDist });
                        }

                }

                
        }

        cout << dist[goal] << '\n';

        stack<int> res;
        res.push(goal);
        while (1)
        {
                res.push(before[goal]);
                if (before[goal] == start)
                        break;
                goal = before[goal];
        }

        cout << res.size() << '\n';

        while (!res.empty())
        {
                cout << res.top() << ' ';
                res.pop();
        }
        
        cout << '\n';

        return 0;
}
