#include <iostream>
#include <vector>
#include <numeric>
using std::vector;

int main(void) {							//���� 1037 ���
	int N;									//�̰� Ʈ���Ѱ� ��ü �Է��� �ּҰ������ �ǰڴٰ�
	std::cin >> N;							//�����ߴµ� �ƴ�

	vector<int> myVector(N);				// �׳� 1, �ڱ��ڽ� ������ ��� ��� �ִϱ� 

	for (int i = 0; i < N; i++) {			// ����������X����ū�� �ϸ� ������ ���͹���
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

