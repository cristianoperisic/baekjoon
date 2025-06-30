#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int main(void) {										// ���� 23970
	int N;
	std::cin >> N;

	vector<int> myVector1(N);
	vector<int> myVector2(N);

	for (int i = 0; i < N;i++) {
		std::cin >> myVector1[i];
	}
	for (int i = 0; i < N;i++) {
		std::cin >> myVector2[i];
	}

	if (myVector1 == myVector2) {
		std::cout << 1;
		return 0;
	}

	for (int i = 0; i < N;i++) {
		for (int j = 0; j < N - 1 - i;j++) {
			if (myVector1[j] > myVector1[j + 1]) {			//���ϸ鼭 ���� ����
				std::swap(myVector1[j], myVector1[j + 1]);
				if ((myVector1[j] == myVector2[j]) && (myVector1[j + 1] == myVector2[j + 1])) {
					if (myVector1 == myVector2) {      // swap�� �ϰ� ���� �� ���Ұ� myVector2�� ��ġ�ϴ���
						std::cout << 1;				   // Ȯ���ϰ� ��ġ�ϴ��� �˻�
						return 0;
					}
				}
			}
		}
	}
	std::cout << 0;			// loop Ż���ϸ� 0�� ����
	return 0;
}