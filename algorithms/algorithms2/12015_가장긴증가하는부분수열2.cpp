#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        int n, getNum;
        int len = 0;
        int left, right, mid;

        cin >> n;
        vector<int> nums;
        vector<int> partial;

        for (int i = 0; i < n; i++)
        {
                cin >> getNum;
                nums.push_back(getNum);
        }

        partial.push_back(0);

        for (int i = 0; i < n; i++)
        {
                if (nums[i] > partial.back())
                {
                        partial.push_back(nums[i]);
                        len++;
                        // for(int i = 0; i < partial.size(); i++)
                        //     cout << partial[i] << ' ';
                        // cout << endl;
                }
                else
                {
                        //num이상의 값이 처음으로 나타나는 위치에 num을 넣는다.
                        int index = lower_bound(partial.begin(), partial.end(), nums[i]) - partial.begin();
                        partial[index] = nums[i];

                        // left = 0;
                        // right = partial.size();

                        // while(right - left > 0)
                        // {
                        //     mid = (left + right) / 2;
                        //     if(partial[mid] < nums[i])
                        //     {
                        //         left = mid + 1;
                        //     }
                        //     else
                        //     {
                        //         right = mid;
                        //     }

                        // }
                        // partial[right] = nums[i];
                }

        }

        cout << len << '\n';

        return 0;

}