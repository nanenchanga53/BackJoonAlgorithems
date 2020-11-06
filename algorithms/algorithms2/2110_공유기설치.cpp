#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        int n, c;
        vector<int> houses;
        houses.reserve(n);
        cin >> n >> c;

        int house;
        for (int i = 0; i < n; i++)
        {
                cin >> house;
                houses.push_back(house);
        }
        sort(houses.begin(), houses.end());

        int left = 1;
        int right = houses.back();
        int ans, mid, cnt;

        while (left <= right)
        {
                mid = (left + right) / 2;
                cnt = 1;

                int now = houses.front();
                for (int i = 1; i < houses.size(); i++)
                {
                        if (houses[i] - now >= mid)
                        {
                                now = houses[i];
                                cnt++;
                        }
                }

                if (cnt < c)
                {
                        right = mid - 1;
                }
                else
                {
                        ans = mid;
                        left = mid + 1;
                }

        }

        cout << ans;
        cout << '\n';

        return 0;
}