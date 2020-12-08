#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<stack>
using namespace std;


int n, getNum;
int len = 0;
//벡터는 리스트지만 편의를 위해 별이라고 설명에 적음
vector<int> nums; //숫자를 입력할 배열
vector<int> partial; //길이를 구하기 위한 배열 순서대로 커지면 순서대로 넣지만 더 작은 숫자가 중간에 생기면 그 숫자를 해당 위치에 덮어 씌울 수 있게 만든다.(덮어쓰여도 최대 길이를 구하는데 문제가 안된다)
vector<int> numPoints; //각 숫자가 새로운 위치에 위치하면 몇 번째 위치에 들어가게 되었는지 기억하는 배열 (1,2,3,1,2,4) 이런식으로 기억되면 1,2,3,4 가순서대로 선택하게 만들면 된다(길이는 알테니뒤에서부터 찾으면 될것이다)
stack<int> resNums; //결과물을 역순으로 입력하기 위한 스택

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
                //partial 배열 중 가장 뒤(가장큰 숫자) 보다 현재 검색하는 숫자가 크다면 추가
                if (nums[i] > partial.back())
                {
                        //partial 배열 중 가장 큰 숫자를 뒤에 추가한다.
                        partial.push_back(nums[i]);
                        len++; //최대길이 증가
                        numPoints[i] = len;
                }
                else
                {
                        //num이상의 값이 처음으로 나타나는 위치에 num을 넣는다.
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