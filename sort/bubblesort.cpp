#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int main(void) {
	int N,K;
	int n = 0;
	std::cin >> N >> K;                                             // 백준 23968

	vector<int> myVector(N);

	for (int i = 0; i < N;i++) {
		std::cin >> myVector[i];
	}

	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N - 1 - i;j++) {
			if (myVector[j] > myVector[j + 1]) {
				std::swap(myVector[j], myVector[j + 1]);
				n++;
			}
			if (n == K) {
				std::cout << myVector[j] << ' ' << myVector[j + 1];
				n++;
			}
		}
	}
	if (n < K)
		std::cout << -1;

	return 0;
}
