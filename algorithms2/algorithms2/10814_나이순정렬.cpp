#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#include<vector>
using namespace std;

class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	bool operator <(const Person& a) const {
		return this->age < a.age;
	}

};

int main()
{
	ios::sync_with_stdio(false);

	vector<Person> arr;
	int n;
	int old;
	string name;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> old >> name;
		arr.push_back(Person(name,old));
	}
	stable_sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", arr[i].age, arr[i].name.c_str());
	}

	return 0;
}