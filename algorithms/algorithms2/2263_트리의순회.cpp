#include<iostream>
#include<algorithm>
using namespace std;

int inord[100001] = { 0, }, postord[100001] = { 0, };

void freeord(int inl, int inr, int pol, int por)
{
	if (pol > por)
		return;
	cout << postord[por] << ' ';
	freeord(inl, inord[postord[por]] - 1,pol ,inord[postord[por]] - 1 - inl + pol);
	freeord(inord[postord[por]] + 1, inr, por - inr + inord[postord[por]],por - 1);

}

int main()
{
	int n;
	cin >> n;

	for (int i = 0, t; i < n; i++)
	{
		cin >> t;
		inord[t] = i;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> postord[i];
	}

	freeord(0, n - 1, 0, n - 1);

	system("pause");
	return 0;
 }