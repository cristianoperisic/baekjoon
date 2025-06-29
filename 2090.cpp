#include <iostream>
#include <numeric>
#include <vector>
using std::vector;

long long gcd(long long a, long long b) {				// 최대 공약수        오버플로우 대비해서 long long 반환
	if (a < b)
		std::swap(a, b);

	long long r;
	while (b != 0) {									// 두 수의 나머지와 작은 수를 계속 비교해가며
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

long long lcm(long long a, long long b) {				// 최소 공배수
	return a / gcd(a, b) *b;							// 오버플로우 대비해서 나누고 곱함
}

int main(void) {
	int N;
	std::cin >> N;

	if (N == 1) {
		int k;
		std::cin >> k;
		std::cout << k<<'/'<<1;

		return 0;
	}

	vector<int> myVector(N);
	for (int i = 0; i < N; i++) {
		std::cin >> myVector[i];
	}

	long long max = myVector[0];

	for (int i = 1; i < N;i++) {
		max = lcm(max, myVector[i]);					// N개의 수의 최대공약수
	}

	long long a = max;
	long long b=0;

	for (int i = 0; i < N;i++) {
		b += max / myVector[i];
	}

	long long min = gcd(a, b);

	std::cout << a/min<< '/' << b/min;

	return 0;
}