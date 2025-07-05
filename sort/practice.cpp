#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;					// น้มุ 2751น๘

int main(void) {
	int N;
	std::cin >> N;

	vector<int> A(N);

	for (int i = 0; i < N;i++) {
		std::cin >> A[i];
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < N;i++) {
		std::cout << A[i] << '\n';
	}

	return 0;
}