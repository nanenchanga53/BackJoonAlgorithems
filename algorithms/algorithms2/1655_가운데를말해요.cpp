#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        // ���ڰ� Ŀ���� priority_queue (�������� ����ִ´�)
        priority_queue<int> biggerPQ;
        //���ڰ� �۾����� priority_queue (ū ���� ����ִ´�);
        priority_queue<int, vector<int>, greater<int>> lowerPQ;

        int n, num;

        biggerPQ.push(-10001);
        lowerPQ.push(10001);

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                cin >> num;
                // �����ϴ� ť�� ������ ������ ������ �Ϳ� �ִ´�
                if (biggerPQ.size() <= lowerPQ.size())
                {
                        biggerPQ.push(num);
                }
                // �۾����� ť�� ������ ������ �۾����� �Ϳ� �ִ´�
                else if (biggerPQ.size() > lowerPQ.size())
                {
                        lowerPQ.push(num);
                }

                // �����ϴ� ť�� ���� ū ���� �۾����� ť�� ������ ũ�ٸ� swap
                if (biggerPQ.top() > lowerPQ.top())
                {
                        int tmp;
                        tmp = lowerPQ.top();
                        lowerPQ.pop();
                        lowerPQ.push(biggerPQ.top());
                        biggerPQ.pop();
                        biggerPQ.push(tmp);
                }

                //���ڰ� Ŀ���� priority_queue�� ���� ū���� �߰����̴�.
                cout << biggerPQ.top() << '\n';
        }

        return 0;

}