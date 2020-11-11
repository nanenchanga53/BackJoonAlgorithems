#include<iostream>
#include<algorithm>
#include<cstring>        //memset

using namespace std;

int n, m;
int nums[2001];
bool dp[2001][2001];

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        int left, right;

        memset(dp, false, sizeof(dp));

        cin >> n;

        for (int i = 0; i < n; i++)
        {
                cin >> nums[i];
                dp[i][i] = true;
                if (i > 0 && nums[i] == nums[i - 1])
                        dp[i - 1][i] = dp[i][i - 1] = true;
        }

        for (int i = 2; i < n; i++)
        {
                for (int j = 0; j < n - i; j++)
                {
                        if (nums[j] == nums[j + i] && dp[j + 1][j + i - 1])
                        {
                                dp[j][j + i] = dp[j + i][j] = true;
                        }
                }
        }

        cin >> m;
        
        for (int i = 0; i < m; i++)
        {
                cin >> left >> right;
                cout << (dp[left-1][right-1] == true ? 1 : 0) << '\n';
        }


        return 0;
}
