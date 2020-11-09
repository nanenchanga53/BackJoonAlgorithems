#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        // 숫자가 커지는 priority_queue (작은수를 집어넣는다)
        priority_queue<int> biggerPQ;
        //숫자가 작아지는 priority_queue (큰 수를 집어넣는다);
        priority_queue<int, vector<int>, greater<int>> lowerPQ;

        int n, num;

        biggerPQ.push(-10001);
        lowerPQ.push(10001);

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                cin >> num;
                // 증가하는 큐의 개수가 같으면 증가는 것에 넣는다
                if (biggerPQ.size() <= lowerPQ.size())
                {
                        biggerPQ.push(num);
                }
                // 작아지는 큐의 개수가 적으면 작아지는 것에 넣는다
                else if (biggerPQ.size() > lowerPQ.size())
                {
                        lowerPQ.push(num);
                }

                // 증가하는 큐의 가장 큰 값이 작아지는 큐의 값보다 크다면 swap
                if (biggerPQ.top() > lowerPQ.top())
                {
                        int tmp;
                        tmp = lowerPQ.top();
                        lowerPQ.pop();
                        lowerPQ.push(biggerPQ.top());
                        biggerPQ.pop();
                        biggerPQ.push(tmp);
                }

                //숫자가 커지는 priority_queue의 가장 큰값이 중간값이다.
                cout << biggerPQ.top() << '\n';
        }

        return 0;

}