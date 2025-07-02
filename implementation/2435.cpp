#include <iostream>
#include <vector>
using std::vector;

int main(void) {
	int N, K;
	std::cin >> N >> K;

	vector<int> sequence(N);
	vector<int> sum(N - K + 1);

	for (int i = 0; i < N; i++) {
		std::cin >> sequence[i];
	}

	for (int i = 0; i < N - K + 1; i++) {
		int k = i;
		for (int j = 0; j < K;j++) {
			sum[i] += sequence[k++];
		}
	}

	int max=sum[0];

	for (int i = 1; i < N - K+1;i++) {
		if (max < sum[i])
			max = sum[i];
	}

	std::cout << max;

	return 0;
}
