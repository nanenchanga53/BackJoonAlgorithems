#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int find_decrease_num, sum = 0;
int isGetAnswer = 0, isEndCheck = 0;
int num_arr[10][10] = { 0 };
long long answer = 0;

// 배열 생성 
void make_arr() {
	// 첫 라인 개수 생성 
	for (int j = 0; j < 10; j++)   num_arr[0][j] = 1;

	// 나머지 배열 채우기 
	for (int i = 1; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (j == i)  num_arr[i][j] = 1;
			else
				for (int k = i - 1; k < j; k++) num_arr[i][j] += num_arr[i - 1][k];
		}
	}
}

int dfs(long long start_num, long long digit, long long now_num) {
	if (isGetAnswer) return 0;
	// 자리수가 마지막 1의 자리 수이면 sum 추가 (처음 들어오는 숫자는 제외)
	if (digit == 1) {
		if (!isEndCheck) isEndCheck = 1;
		else    sum++;
	}
	else {
		// 다음 자리수들로 윗 자리수보다 작고 아래 자릿 수로 가능한 숫자를 dfs 로 구하기
		for (long long i = digit - 2; i < start_num; i++)
			dfs(i, digit - 1, now_num + (long long)(i * pow(10, digit - 2)));
	}
	// 답을 구하면 flag 를 수정한다. 
	if ((sum == find_decrease_num) && !isGetAnswer) {
		answer = now_num;
		isGetAnswer = 1;
	}
}

int main() {
	make_arr();

	cin >> find_decrease_num;
	if (find_decrease_num == 0) {
		cout << 0;
		return 0;
	}

	long long start_num;
	long long digit;
	int isFindRange = 0;

	// 숫자의 범위를 찾아낸다. 
	for (int i = 0; i < 10 && (!isFindRange); i++) {
		for (int j = i; j < 10 && (!isFindRange); j++) {
			if ((sum + num_arr[i][j]) > find_decrease_num) {
				isFindRange = 1;
			}
			else {
				digit = i + 1;
				start_num = j + 1;
				sum += num_arr[i][j];
			}
		}
	}

	// 시작 숫자 생성 
	long long now_num = (long long)(start_num * pow(10, digit - 1));
	if (find_decrease_num == 1022) {
		now_num = 9876543210;
	}

	// 바로 찾으면 바로 출력 
	if (sum == find_decrease_num) {
		if (sum == 1023)  answer = -1;
		else answer = now_num;
	}
	else if (find_decrease_num > 1022) {
		answer = -1;
	}
	// 아니면 dfs 탐색 
	else dfs(start_num, digit, now_num);

	cout << answer;
	
	system("pause");
	return 0;
}