#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

int a, b,T;
int usedNum[10001] = { 0, };
pair<int,char> before[10001];
stack<int> res;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        const int divNum = 10000;

        cin >> T;
        while (T--)
        {
                memset(usedNum, 0, sizeof(usedNum));
                queue<int> que;

                cin >> a >> b;

                usedNum[a] = 1;

                que.push(a);

                int now;

                while (!que.empty())
                {
                        now = que.front();
                        que.pop();

                        if (now == b)
                                break;

                        //D 2배 % 10000
                        int numD = now * 2 % divNum;
                        if (usedNum[numD] == 0)
                        {
                                usedNum[numD] = usedNum[now] + 1;
                                que.push(numD);
                                before[numD].first = now;
                                before[numD].second = 'D';

                                if (numD == b)
                                        break;
                        }

                        //S -1 0이되면 9999
                        int numS = now == 0 ? 9999 : now - 1;
                        if (usedNum[numS] == 0)
                        {
                                usedNum[numS] = usedNum[now] + 1;
                                que.push(numS);
                                before[numS].first = now;
                                before[numS].second = 'S';

                                if (numS == b)
                                        break;
                        }

                        //L 자리수를 왼쪽으로 변경
                        int numL = ((now * 10) + (now / 1000)) % divNum;
                        if (usedNum[numL] == 0)
                        {
                                usedNum[numL] = usedNum[now] + 1;
                                que.push(numL);
                                before[numL].first = now;
                                before[numL].second = 'L';

                                if (numL == b)
                                        break;
                        }

                        //R 자리수를 오른쪽으로 변경
                        int numR = ((now % 10) * 1000) + (now / 10);
                        if (usedNum[numR] == 0)
                        {
                                usedNum[numR] = usedNum[now] + 1;
                                que.push(numR);
                                before[numR].first = now;
                                before[numR].second = 'R';

                                if (numR == b)
                                        break;
                        }
                }

                stack<char> res;

                while (1)
                {
                        res.push(before[b].second);
                        if (before[b].first == a)
                                break;
                        b = before[b].first;
                }

                while (!res.empty())
                {
                        cout << res.top();
                        res.pop();
                }

                cout << '\n';
        }

        
        return 0;
}
