#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using std::vector;
// 백준 1259번 팰린드롬수
int digit(int);
bool palindrome(int);
int power(int a, int b);


int main(void) {
	vector<std::string> A;
	
	int n;
	std::cin >> n;
	while (n != 0) {
		if (palindrome(n) == true) {
			A.push_back("yes");
		}
		else
			A.push_back("no");
		std::cin >> n;
	}

	for (std::string x : A) {
		std::cout << x << '\n';
	}

	return 0;
}

bool palindrome(int n) {
	int num = digit(n);
	if (num == 1) {
		return true;
	}
	else if (num % 2 == 1 || num % 2 == 0) {        // n 이 홀수 자릿수?
		for (int i = 1;i <= num / 2;i++) {
			if ((n % power(10, i)) / power(10, i - 1) != (n % power(10, num - i + 1) / power(10, num - i))) {

				return false;
			}
		}

		return true;

	}
}
int digit(int n) {					// 몇자리수인데?
	int k = 1;
	int cnt = 0;
	while (n / k != 0) {
		k *= 10;
		cnt++;
	}
	return cnt;
}

int power(int a, int b) {
	int result = 1;
	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}
