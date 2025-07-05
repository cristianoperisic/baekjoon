#include <iostream>
#include <vector>
#include <numeric>
using std::vector;					// ���� 2609��

int gcd(int a, int b) {				// �ִ� ����� the greatest common dominator
	if (a < b) {
		std::swap(a, b);
	}

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lcm(int a,int b) {				// �ּ� ����� the least common multiple
	return a / gcd(a, b) * b;
}

int main(void) {
	int a, b;
	std::cin >> a >> b;

	std::cout << gcd(a,b)<< '\n'<<lcm(a, b);

	return 0;
}