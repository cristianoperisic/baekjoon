#include <iostream>
#include <numeric>
#include <vector>
using std::vector;

long long gcd(long long a, long long b) {				// �ִ� �����        �����÷ο� ����ؼ� long long ��ȯ
	if (a < b)
		std::swap(a, b);

	long long r;
	while (b != 0) {									// �� ���� �������� ���� ���� ��� ���ذ���
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

long long lcm(long long a, long long b) {				// �ּ� �����
	return a / gcd(a, b) *b;							// �����÷ο� ����ؼ� ������ ����
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
		max = lcm(max, myVector[i]);					// N���� ���� �ִ�����
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