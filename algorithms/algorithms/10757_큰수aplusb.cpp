#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>

using namespace std;

//범위가 long long 형 2개로 나눌 수 있는 경우
//#define ll long long
//#define CHIPER_CNT 18 //최대 범위
//
//static const ll CIPHER = pow(10, CHIPER_CNT);
//
//using namespace std;
//
//typedef struct BigInteger
//{
//	ll high; //높은 자리 숫자
//	ll low; // 낮은 자리 숫자
//} BI;
//
//BI llToBi(ll li)
//{
//	return { 0, li };
//}
//
//BI BiAddBi(BI a, BI b)
//{
//	ll tlow = a.low % CIPHER + b.low % CIPHER;
//	ll thigh = 0;
//	if (tlow % CIPHER != a.low + b.low) {
//		thigh = a.low / CIPHER + b.low / CIPHER;
//	}
//	thigh += a.high + b.high;
//	return { thigh, tlow };
//}

vector<int> res;

void Operate(string a, string b)
{
	int aLen = a.length();
	int bLen = b.length();
	int resLen = aLen + 1;
	res.resize(resLen, 0);

	
	int carry = 0;
	int aNum, bNum;
	while(aLen > 0)
	{
		bLen--;
		aLen--;
		resLen--;

		aNum = a.at(aLen) - '0';
		

		if (bLen >= 0)
		{
			bNum = b.at(bLen) - '0';
			res[resLen] = (aNum + bNum + res[resLen]);

			if (res[resLen] >= 10)
				res[resLen - 1]++;

			res[resLen] %= 10;
				
		}
		else if(aLen >= 0)
		{
			res[resLen] = (aNum + res[resLen]);
			
			if (res[resLen] >= 10)
				res[resLen - 1] ++;

			res[resLen] %= 10;
		}

	}

	return;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string a, b;

	cin >> a >> b;

	if (a.length() >= b.length())
	{
		Operate(a, b);
	}
	else
	{
		Operate(b, a);
	}

	for (int i = 0; i < res.size() ; i++)
	{
		if (i == 0 && res[i] == 0)
			continue;
		cout << res[i];
	}
	cout << endl;

	return 0;

}