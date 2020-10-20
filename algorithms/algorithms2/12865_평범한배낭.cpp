#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

struct NapSac
{
	int weight;
	int value;
};



int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	std::cin >> n >> k;
	
	//아래는 포인터를 이용한 배열선언인데 그냥 벡터같은거 쓰자
	//배열[배낭의무게][이전까지선택된가방]
	int** arr = new int* [k + 1];
	for (int i = 0; i <= k; i++)
	{
		arr[i] = new int[n + 1];
		std::fill_n(arr[i], n + 1, 0);
	}

	//정보를 받아올 배열
	NapSac* sacArr = new NapSac[n + 1];
	for (int i = 1; i <= n; i++)
	{
		std::cin >> sacArr[i].weight >> sacArr[i].value;
	}

	//현제무게
	for (int sacWeight = 1; sacWeight <= k; sacWeight++)
	{
		//현제선택된 가방
		for (int sacValue = 1; sacValue <= n; sacValue++)
		{
			//현재 가방
			NapSac napsac = sacArr[sacValue];
			if (sacWeight >= napsac.weight)
			{
				//***  왼쪽별처럼 배열을 채우며 왼쪽과 자신의 무게를 더했을때의 가치를 비교후 더 큰 것을 배열에 넣는다
				// **
				//  *
				arr[sacWeight][sacValue] = max(arr[sacWeight][sacValue - 1], arr[sacWeight - napsac.weight][sacValue - 1] + napsac.value);
			}
			else
			{
				//  선택할 수 있는 부게가 된되서 그냥 왼쪽걸 넣는다.
				arr[sacWeight][sacValue] = arr[sacWeight][sacValue - 1];
			}

		}
	}

	cout << arr[k][n];

	
	return 0;
}