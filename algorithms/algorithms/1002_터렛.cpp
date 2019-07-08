// r , r'  �� ���� ������   d  ���� �߽� ������ ����
//���� r + r' = d   1���� //��
//���� r - r' = d   1����
//������ ��ġ�� ��  �������� ������ d=0 -1����
//������ �ʰ� ū�� �ȿ� ���� ��  d < r'-r  0����
//�ƿ� �ȸ��� r + r' < d  0����
//�׿ܴ� ���� �� ���� ������ r'-r < d < r' + r 2����
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;


int main()
{
	int n;
	int x1, y1, x2, y2, r1, r2;
	int d, rSum, rMin;
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		d = pow((x1 - x2), 2) + pow((y1 - y2), 2);
		rSum = r1 + r2;
		rMin = abs(r1 - r2);

		if (x1 == x2 && y1 == y2)// ������ ������
		{
			if (r1 == r2) //�������� ������
				res = -1;
			else //�������� �ٸ���
				res = 0;
		}
		else //������ �ٸ���
		{
			if (rMin < sqrt(d) && sqrt(d) < rSum) // 2�� ������
				res = 2;
			else if (rMin == sqrt(d)) // ����
				res = 1;
			else if (rSum == sqrt(d)) // ����
				res = 1;
			else if (rSum < sqrt(d)) //������ �ʴ� ��
				res = 0;
			else if (sqrt(d) == rSum) //����
				res = 1;
			else if (sqrt(d) < rMin) //�߽��� �ٸ��� ������ �ʴ� ��
				res = 0;
		}	

		cout << res << endl;
	}
	return 0;
}