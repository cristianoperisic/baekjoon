#include <iostream>
#include <vector>
#include <numeric>
using std::vector;

int main(void) {							//백준 1037 약수
	int N;									//이거 트롤한게 전체 입력의 최소공배수면 되겠다고
	std::cin >> N;							//생각했는데 아님

	vector<int> myVector(N);				// 그냥 1, 자기자신 제외한 모든 약수 주니까 

	for (int i = 0; i < N; i++) {			// 제일작은거X제일큰거 하면 본인이 나와버림
		std::cin >> myVector[i];
	}

	int max = myVector[0];

	for (int i = 1; i < N; i++) {
		if (max < myVector[i])
			max = myVector[i];
	}
	int min = myVector[0];
	for (int i = 1; i < N; i++) {
		if (min > myVector[i])
			min = myVector[i];
	}

	std::cout << max*min;

	return 0;
}

