//2839번: 설탕배달 문제
// 3x + 5y = N 을 만드는 문제, x+y의 최솟값은?
// 어떻게 만드냐.. y가 커질 수록 x+y는 작아지는 구조임. 즉, 최대한의 y를 담으려면?
// 나열을 해보니까 x+y가 짝수면 3x+5y는 짝수, 홀수면 홀수이고 4, 7은 나올 수 없음
// 그래서 .. 끝자리에서 최소의 3의 배수를 제거하고 5로 채움

#include <iostream>

int main() {
	int N;
	std::cin >> N;

	if (N == 4 || N == 7) {        // 예외처리:4,7은 나올 수 없음
		std::cout << -1;
		return 0;
	}

	switch (N % 10) {
	case 0:
		std::cout << N / 5;
		break;

	case 1:
		if (N == 11) {
			std::cout << 3;
			break;
		}
		std::cout << ((N - 21) / 5 + 5); // 21은 15+6
		break;

	case 2:
		std::cout << ((N - 12) / 5 + 4); // 12는 12
		break;

	case 3:
		std::cout << ((N - 3) / 5 + 1); // 3은 3
		break;

	case 4:
		if (N == 14) {
			std::cout << 4;
			break;
		}
		std::cout << ((N - 24) / 5 + 6); // 24는 15+9
		break;

	case 5:
		std::cout << (N / 5);
		break;

	case 6:
		std::cout << ((N - 6) / 5 + 2);  // 6은 6
		break;

	case 7:
		if (N == 17) {
			std::cout << 5;
			break;
		}
		std::cout << ((N - 27) / 5 + 7); // 27은 15+12
		break;

	case 8:
		if (N == 8) {
			std::cout << 2;
			break;
		}
		std::cout << ((N - 18) / 5 + 4); // 18은 15+3
		break;

	case 9:
		std::cout << ((N - 9) / 5 + 3);  // 9는 9 
		break;
	}

	return 0;
}
