#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<stack>
using namespace std;


int n, getNum;
int len = 0;
//���ʹ� ����Ʈ���� ���Ǹ� ���� ���̶�� ���� ����
vector<int> nums; //���ڸ� �Է��� �迭
vector<int> partial; //���̸� ���ϱ� ���� �迭 ������� Ŀ���� ������� ������ �� ���� ���ڰ� �߰��� ����� �� ���ڸ� �ش� ��ġ�� ���� ���� �� �ְ� �����.(������� �ִ� ���̸� ���ϴµ� ������ �ȵȴ�)
vector<int> numPoints; //�� ���ڰ� ���ο� ��ġ�� ��ġ�ϸ� �� ��° ��ġ�� ���� �Ǿ����� ����ϴ� �迭 (1,2,3,1,2,4) �̷������� ���Ǹ� 1,2,3,4 ��������� �����ϰ� ����� �ȴ�(���̴� ���״ϵڿ������� ã���� �ɰ��̴�)
stack<int> resNums; //������� �������� �Է��ϱ� ���� ����

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
                

        cin >> n;
        

        numPoints.resize(n);

        for (int i = 0; i < n; i++)
        {
                cin >> getNum;
                nums.push_back(getNum);
        }

        partial.push_back(-1000000001);

        for (int i = 0; i < n; i++)
        {
                //partial �迭 �� ���� ��(����ū ����) ���� ���� �˻��ϴ� ���ڰ� ũ�ٸ� �߰�
                if (nums[i] > partial.back())
                {
                        //partial �迭 �� ���� ū ���ڸ� �ڿ� �߰��Ѵ�.
                        partial.push_back(nums[i]);
                        len++; //�ִ���� ����
                        numPoints[i] = len;
                }
                else
                {
                        //num�̻��� ���� ó������ ��Ÿ���� ��ġ�� num�� �ִ´�.
                        int index = lower_bound(partial.begin(), partial.end(), nums[i]) - partial.begin();
                        partial[index] = nums[i];
                        numPoints[i] = index;

                }

        }

        cout << len << '\n';

        for (int i = n - 1; i >= 0; i--)
        {
                if (numPoints[i] == len)
                {
                        resNums.push(nums[i]);
                        len--;
                }            
        }

        while (!resNums.empty())
        {
                cout << resNums.top() << ' ';
                resNums.pop();
        }
        cout << '\n';

        return 0;

}