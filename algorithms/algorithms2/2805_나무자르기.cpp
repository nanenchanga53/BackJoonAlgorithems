#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool SliceTree(vector<int> trees, int h, int target)
{
        long long sum = 0;
        for (int i = 0; i < trees.size(); i++)
        {
                sum += trees[i] - h > 0 ? trees[i] - h : 0;
        }

        if (sum >= target)
        {
                return true;
        }

        return false;
}

//Longest Length Serch
int LLSerch(vector<int> trees, int s, int l, int target)
{
        while (s <= l)
        {
                int mid = (s + l) / 2;
                if (SliceTree(trees, mid, target))
                {
                        s = mid + 1;
                        //cout << s << ' ' << l <<  ' ' << mid << '\n';
                }
                else
                {
                        l = mid - 1;
                        //cout << s << ' ' << l <<  ' ' << mid << '\n';
                }

        }
        return l;

}


int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);
        int n, m, tree, bigtree = -1;
        vector<int> trees;

        cin >> n;
        cin >> m;

        for (int i = 0; i < n; i++)
        {
                cin >> tree;
                bigtree = bigtree < tree ? tree : bigtree;
                trees.push_back(tree);
        }
        sort(trees.begin(), trees.begin() + n);
        bigtree = (bigtree * 2) + 1 < 2000000000 ? (bigtree * 2) + 1 : 2000000000;

        cout << LLSerch(trees, 0, bigtree, m);

        return 0;

}