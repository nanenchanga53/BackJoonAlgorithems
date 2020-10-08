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

////단어를 출력하려면
//copy(istream_iterator<string>(iss),
//	istream_iterator<string>(),
//	ostream_iterator<string>(cout, "\n"));
//
////단어를 container에 저장하려면
//vector<string> words;
//copy(istream_iterator<string>(iss),
//	istream_iterator<string>(),
//	back_inserter(words));
//
////벡터를 바로 생성하려면
//vector<string> wordsVector{ istream_iterator<string>{iss},
//istream_iterator<string>{} };