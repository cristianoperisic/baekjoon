#include <iostream>
#include <vector>
using std::vector;

int main(void) {							// 선택 정렬 백준 23881번 문제
	int N, K, max;
	std::cin >> N >> K;
	int n = 0;
	int index = 0;
	int temp = 0;


	vector<int> myVector(N);
	for (int i = 0; i < N;i++) {
		std::cin >> myVector[i];
	}

	for (int i = N-1; i > 0;i--) {						// i>0인 이유는 myVector[0]에서는 굳이 loop을 돌릴 필요가 없음
		max = 0;										// 어차피 입력이 1이상이라 max를 0으로 초기설정
		for (int j = i;j >= 0;j--) {					// j>=0인 이유는 여기서는 0번째 인덱스도 검사를 해야함
			if (max < myVector[j]) {
				max = myVector[j];
				index = j;
			}
		}
		temp = myVector[i];
		myVector[i] = myVector[index];
		myVector[index] = temp;
		if(i!=index)									// 만약 바꿨으면 n을 하나 증가 
			n++;
		


		if (n == K) {
			std::cout << myVector[index] <<' '<< myVector[i];  // n==K인 시점에 출력을 해버리자
		}
		
	}
	
	if (n < K)												// n이 K에 도달 못하면 -1을 출력
		std::cout << -1;

	return 0;
}