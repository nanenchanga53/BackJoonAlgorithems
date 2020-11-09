#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct cmp
{
        bool operator()(const int& a, const int& b)
        {
                if (abs(a) == abs(b))
                {
                        return a > b;
                }
                else
                {
                        return abs(a) > abs(b);
                }
        }
};

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        priority_queue<int, vector<int>, cmp> pq;

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