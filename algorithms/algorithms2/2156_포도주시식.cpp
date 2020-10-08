#include<iostream>
#include<algorithm>
using namespace std;

int score[10002] = { 0, };
int sum[10002] = { 0, };
int n;

int serch()
{
	int wine,maxNum;
	maxNum = max(max(score[1],score[2]),score[1] + score[2]);

	for (wine = 3; wine <= n; wine++)
	{
		sum[wine] = max(sum[wine-1],max(score[wine] + sum[wine - 2], score[wine] + score[wine-1] + sum[wine-3]));

		
	}


	return sum[n];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> score[i];
	sum[1] = score[1];
	sum[2] = max(max(score[1],score[2]),score[1] + score[2]);
	

	cout << serch() << endl;
	system("pause");
	return 0;
}