#include <iostream>
#include <vector>
using std::vector;

int main(void) {							// ���� ���� ���� 23881�� ����
	int N, K, max;
	std::cin >> N >> K;
	int n = 0;
	int index = 0;
	int temp = 0;


	vector<int> myVector(N);
	for (int i = 0; i < N;i++) {
		std::cin >> myVector[i];
	}

	for (int i = N-1; i > 0;i--) {						// i>0�� ������ myVector[0]������ ���� loop�� ���� �ʿ䰡 ����
		max = 0;										// ������ �Է��� 1�̻��̶� max�� 0���� �ʱ⼳��
		for (int j = i;j >= 0;j--) {					// j>=0�� ������ ���⼭�� 0��° �ε����� �˻縦 �ؾ���
			if (max < myVector[j]) {
				max = myVector[j];
				index = j;
			}
		}
		temp = myVector[i];
		myVector[i] = myVector[index];
		myVector[index] = temp;
		if(i!=index)									// ���� �ٲ����� n�� �ϳ� ���� 
			n++;
		


		if (n == K) {
			std::cout << myVector[index] <<' '<< myVector[i];  // n==K�� ������ ����� �ع�����
		}
		
	}
	
	if (n < K)												// n�� K�� ���� ���ϸ� -1�� ���
		std::cout << -1;

	return 0;
}