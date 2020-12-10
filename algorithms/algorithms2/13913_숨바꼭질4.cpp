#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int n, k;
int visited[100001] = { 0, };
int before[100001] = { 0, };
stack<int> res;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        queue<int> que;

        cin >> n >> k;

        visited[n] = 1;

        que.push(n);

        int now;

        while (!que.empty())
        {
                now = que.front();
                que.pop();

                if (now - 1 >= 0 && visited[now - 1] == 0)
                {
                        que.push(now - 1);
                        visited[now - 1] = visited[now] + 1;
                        before[now - 1] = now;
                }

                if (now + 1 <= 100000 && visited[now + 1] == 0)
                {
                        que.push(now + 1);
                        visited[now + 1] = visited[now] + 1;
                        before[now + 1] = now;
                }

                if (now * 2 <= 100000 && visited[now * 2] == 0)
                {
                        que.push(now * 2);
                        visited[now * 2] = visited[now] + 1;
                        before[now * 2] = now;
                }

        }

        cout << visited[k] - 1 << '\n';
        if (visited[k] - 1 == 0)
        {
                cout << k << '\n';
        }
        else
        {
                res.push(k);
                while (1)
                {
                        res.push(before[k]);
                        if (before[k] == n)
                                break;
                        k = before[k];
                }

                while (!res.empty())
                {
                        cout << res.top() << ' ';
                        res.pop();
                }
        }
        return 0;
}
