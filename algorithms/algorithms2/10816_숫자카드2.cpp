#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m, cardNum, findNum;
unordered_map <int, int> numCards;

bool compare(int a, int b)
{
        return a < b;
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(nullptr), cout.tie(nullptr);

        cin >> n;
        for (int i = 0; i < n; i++)
        {
                cin >> cardNum;
                numCards[cardNum]++;
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
                cin >> findNum;
                cout << numCards[findNum] << ' ';
        }
        return 0;

}

// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<cmath>
// using namespace std;

// vector<int> numCards;
// vector<pair<int,int>> sumCard;
// int main()
// {
//     ios::sync_with_stdio(false);
// 	cin.tie(nullptr), cout.tie(nullptr);

//     int n,m;

//     cin >> n;

//     for(int i = 0; i < n; i++)
//     {
//         int card;
//         cin >> card;
//         numCards.push_back(card);
//     }
//     sort(numCards.begin(), numCards.begin() + n);

//     sumCard.push_back(make_pair(numCards[0],1));
//     for(int i = 1; i < n;i++)
//     {
//         if(numCards[i] == sumCard.back().first)
//             sumCard.back().second++;
//         else
//             sumCard.push_back(make_pair(numCards[i],1));       

//     }

//     cin >> m;
//     int findNum;

//     for(int i = 0; i < m; i++)
//     {
//         int cnt = 0;
//         int left = 0, right = sumCard.size() - 1;
//         cin >> findNum;

//         while(left <= right)
//         {
//             int mid = (left + right) / 2;
//             if(sumCard[mid].first > findNum)
//             {
//                 right = mid - 1;
//             }
//             else if(sumCard[mid].first < findNum)
//             {
//                 left = mid + 1;
//             }
//             else if(sumCard[mid].first == findNum)
//             {
//                 cnt = sumCard[mid].second;
//                 break;
//             }
//         }
//             cout << cnt << ' ';


//     }
//     cout << '\n';

//     return 0;
// }