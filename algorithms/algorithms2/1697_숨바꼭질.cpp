#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, k;
int visited[200001] = { 0, }; //100000 * 2 ��ġ���� Ž���ϴ� ���� ���� �� �����Ƿ�
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
                }
                
                if (now + 1 <= 200000 && visited[now + 1] == 0)
                {
                        que.push(now + 1);
                        visited[now + 1] = visited[now] + 1;
                }

                if (now * 2 <= 200000 && visited[now * 2] == 0)
                {
                        que.push(now * 2);
                        visited[now * 2] = visited[now] + 1;
                }
                
        }

        cout << visited[k] - 1 << '\n';

        return 0;
}
