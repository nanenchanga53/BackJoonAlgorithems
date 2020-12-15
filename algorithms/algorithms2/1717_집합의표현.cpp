#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int parent[1000001];

int FindParent(int num)
{
        if (num == parent[num])
                return num;
        else
        {
                parent[num] = FindParent(parent[num]);
                return parent[num];
        }
}

void Union(int n1, int n2)
{
        n1 = FindParent(n1);
        n2 = FindParent(n2);

        if (n1 != n2)
        {
                parent[n2] = n1;
        }
}


int main()
{

        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> n;
        cin >> m;

        for (int i = 0; i <= n; i++)
        {
                parent[i] = i;
        }
        int testType, num1, num2;
        for (int i = 0; i < m; i++)
        {            
                cin >> testType >> num1 >> num2;

                if (num1 > num2)
                        swap(num1, num2);

                if (testType == 0)
                {
                        num1 = FindParent(num1); //찾으려는 숫자의 최고 부모를 가져온다
                        num2 = FindParent(num2); //찾으려는 숫자의 최고 부모를 가져온다
                        if (num1 != num2) //최고 부모가 다를시 한쪽의 최고 부모를 다른쪽의 최고 부모가 가르키게 한다
                        {
                                parent[num2] = num1;
                        }
                }
                else if (testType == 1)
                {                     
                        num1 = FindParent(num1);
                        num2 = FindParent(num2);
                        if (num1 == num2)
                        {
                                cout << "YES\n";
                        }
                        else
                        {
                                cout << "NO\n";
                        }
                }
        }

        return 0;

}