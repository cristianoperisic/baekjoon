#include <iostream>
#include <vector>
#include <numeric>
using std::vector;					// 백준 2609번

int gcd(int a, int b) {				// 최대 공약수 the greatest common dominator
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

int lcm(int a,int b) {				// 최소 공배수 the least common multiple
	return a / gcd(a, b) * b;
}

int main(void) {
	int a, b;
	std::cin >> a >> b;

	std::cout << gcd(a,b)<< '\n'<<lcm(a, b);

	return 0;
}