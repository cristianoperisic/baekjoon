//2839��: ������� ����
// 3x + 5y = N �� ����� ����, x+y�� �ּڰ���?
// ��� �����.. y�� Ŀ�� ���� x+y�� �۾����� ������. ��, �ִ����� y�� ��������?
// ������ �غ��ϱ� x+y�� ¦���� 3x+5y�� ¦��, Ȧ���� Ȧ���̰� 4, 7�� ���� �� ����
// �׷��� .. ���ڸ����� �ּ��� 3�� ����� �����ϰ� 5�� ä��

#include <iostream>

int main() {
	int N;
	std::cin >> N;

	if (N == 4 || N == 7) {        // ����ó��:4,7�� ���� �� ����
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
		std::cout << ((N - 21) / 5 + 5); // 21�� 15+6
		break;

	case 2:
		std::cout << ((N - 12) / 5 + 4); // 12�� 12
		break;

	case 3:
		std::cout << ((N - 3) / 5 + 1); // 3�� 3
		break;

	case 4:
		if (N == 14) {
			std::cout << 4;
			break;
		}
		std::cout << ((N - 24) / 5 + 6); // 24�� 15+9
		break;

	case 5:
		std::cout << (N / 5);
		break;

	case 6:
		std::cout << ((N - 6) / 5 + 2);  // 6�� 6
		break;

	case 7:
		if (N == 17) {
			std::cout << 5;
			break;
		}
		std::cout << ((N - 27) / 5 + 7); // 27�� 15+12
		break;

	case 8:
		if (N == 8) {
			std::cout << 2;
			break;
		}
		std::cout << ((N - 18) / 5 + 4); // 18�� 15+3
		break;

	case 9:
		std::cout << ((N - 9) / 5 + 3);  // 9�� 9 
		break;
	}

	return 0;
}