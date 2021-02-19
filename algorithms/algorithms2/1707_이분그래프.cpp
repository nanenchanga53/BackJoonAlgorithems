#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAXNUM 20001
#define RED  1
#define BLUE -1

int K, v, e;
int visited[MAXNUM];

vector<int> graph[MAXNUM];

void bfs(int start)
{
        queue<int> qu;
        int color = RED;

        visited[start] = color;
        qu.push(start);

        while (!qu.empty())
        {
                int now = qu.front();
                qu.pop();

                if (visited[now] == RED)
                {
                        color = BLUE;
                }
                else if (visited[now] == BLUE)
                {
                        color = RED;
                }

                for (int i = 0; i < graph[now].size(); i++)
                {
                        int next = graph[now][i];
                        if (!visited[next])
                        {
                                visited[next] = color;
                                qu.push(next);
                        }
                }
        }
}

bool isBipartiteGraph()
{
        for (int i = 1; i <= v; i++)
        {
                for (int j = 0; j < graph[i].size(); j++)
                {
                        int next = graph[i][j];
                        if (visited[i] == visited[next])
                                return 0;
                }
        }
        return 1;
}
int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> K;

                while (K--)
        {
                cin >> v >> e;

                for (int i = 0; i < e; i++)
                {
                        int a, b;
                        cin >> a >> b;
                        graph[a].push_back(b);
                        graph[b].push_back(a);

                }

                for (int i = 1; i <= v; i++)
                {
                        if (!visited[i])
                                bfs(i);
                }

                if (isBipartiteGraph())
                {
                        cout << "YES" << "\n";
                }
                else
                {
                        cout << "NO" << "\n";
                }

                for (int i = 0; i <= v; i++) {
                        graph[i].clear();
                }
                memset(visited, false, sizeof(visited));

        }

        return 0;

}