#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string myText("some-text-to-tokenize");

	getline(cin, myText);

	istringstream iss(myText);
	string token;
	while (getline(iss, token, '-'))
	{
		std::cout << token[0];
	}
	cout << endl;

	system("pause");
	return 0;
}

////�ܾ ����Ϸ���
//copy(istream_iterator<string>(iss),
//	istream_iterator<string>(),
//	ostream_iterator<string>(cout, "\n"));
//
////�ܾ container�� �����Ϸ���
//vector<string> words;
//copy(istream_iterator<string>(iss),
//	istream_iterator<string>(),
//	back_inserter(words));
//
////���͸� �ٷ� �����Ϸ���
//vector<string> wordsVector{ istream_iterator<string>{iss},
//istream_iterator<string>{} };