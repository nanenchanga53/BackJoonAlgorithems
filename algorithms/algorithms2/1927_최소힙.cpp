
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        priority_queue<int, vector<int>, greater<int>> pq;

        int n, num;

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                cin >> num;
                if (num == 0)
                {
                        if (!pq.empty())
                        {
                                cout << pq.top() << '\n';
                                pq.pop();
                        }
                        else
                                cout << 0 << '\n';
                }
                else
                {
                        pq.push(num);
                }
        }

        return 0;

}