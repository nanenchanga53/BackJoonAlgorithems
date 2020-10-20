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
	
	//�Ʒ��� �����͸� �̿��� �迭�����ε� �׳� ���Ͱ����� ����
	//�迭[�賶�ǹ���][�����������õȰ���]
	int** arr = new int* [k + 1];
	for (int i = 0; i <= k; i++)
	{
		arr[i] = new int[n + 1];
		std::fill_n(arr[i], n + 1, 0);
	}

	//������ �޾ƿ� �迭
	NapSac* sacArr = new NapSac[n + 1];
	for (int i = 1; i <= n; i++)
	{
		std::cin >> sacArr[i].weight >> sacArr[i].value;
	}

	//��������
	for (int sacWeight = 1; sacWeight <= k; sacWeight++)
	{
		//�������õ� ����
		for (int sacValue = 1; sacValue <= n; sacValue++)
		{
			//���� ����
			NapSac napsac = sacArr[sacValue];
			if (sacWeight >= napsac.weight)
			{
				//***  ���ʺ�ó�� �迭�� ä��� ���ʰ� �ڽ��� ���Ը� ���������� ��ġ�� ���� �� ū ���� �迭�� �ִ´�
				// **
				//  *
				arr[sacWeight][sacValue] = max(arr[sacWeight][sacValue - 1], arr[sacWeight - napsac.weight][sacValue - 1] + napsac.value);
			}
			else
			{
				//  ������ �� �ִ� �ΰ԰� �ȵǼ� �׳� ���ʰ� �ִ´�.
				arr[sacWeight][sacValue] = arr[sacWeight][sacValue - 1];
			}

		}
	}

	cout << arr[k][n];

	
	return 0;
}