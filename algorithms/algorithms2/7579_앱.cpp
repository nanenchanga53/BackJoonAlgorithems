#include<iostream>
#include<algorithm>
#include<cstring>        //memset

using namespace std;

int n,m;

int memory[100];
int cost[100];
//cache[i][j]�� i��ġ���� j������� ����� �ִ� �ִ� �޸� ũ��
int cache[100][10001];

int calc_memory(const int& now, const int& maxCost) 
{
        if (now >= n)
                return 0;

        //����(�޸����̼�) Ȱ��
        int &ret = cache[now][maxCost]; //���� ��� ���� �����ϸ� �ð��ʰ����� �׷��� &�� ������

        //�̹� Ž���� �Ϸ�� ���
        if (ret != -1) return ret;

        //���� ���� Ȱ��ȭ
        ret = calc_memory(now + 1, maxCost);

        //���� ���� ��Ȱ��ȭ ��Ű�� ���
        if (cost[now] <= maxCost)
        {
                //���� ���� ��Ȱ��ȭ ��Ű�� ���� ���� ���Ͽ� �� ū �޸𸮸� ����
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

        //����(�޸������̼�)�� Ȱ���ϱ� ���� �ʱ�ȭ
        memset(cache, -1, sizeof(cache));

        int ret = 0;

        //������ �ִ� �ڽ�Ʈ�� 10000���� Ž���� �����ϵ��� ����. (100 * 100 ���� �ڽ�Ʈ�� �� �� �ִ� ���� 0��)
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
