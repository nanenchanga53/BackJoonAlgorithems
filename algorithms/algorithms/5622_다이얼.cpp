#include<iostream>
#include<cstring>
#include<map>
using namespace std;

map<char, int> m;

void mapping()
{
	m.insert(pair<char, int>('A', 2)); //임의 pair

	pair<char, int> p('B', 2);
	m.insert(p); //pair 객체 생성 insert

	m['C'] = 2;
	m['D'] = 3;
	m['E'] = 3;
	m['F'] = 3;
	m['G'] = 4;
	m['H'] = 4;
	m['I'] = 4;
	m['J'] = 5;
	m['K'] = 5;
	m['L'] = 5;
	m['M'] = 6;
	m['N'] = 6;
	m['O'] = 6;
	m['P'] = 7;
	m['Q'] = 7;
	m['R'] = 7;
	m['S'] = 8;
	m['T'] = 8;
	m['U'] = 8;
	m['V'] = 9;
	m['W'] = 9;
	m['X'] = 9;
	m['Y'] = 9;
	m['Z'] = 9;
}

int main()
{
	char dial[16];
	int i, sum;

	sum = 0;
	mapping();

	cin >> dial;
	for (i = 0; i < strlen(dial); i++)
	{
		sum += m[dial[i]];
	}
	sum += i;
	cout << sum << endl;
	system("pause");
	return 0;
}