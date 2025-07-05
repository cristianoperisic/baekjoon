#include <iostream>
#include <vector>
using std::vector;

bool prime_number(int n);		         	// ���� 1978
int main(void) {
	int N;
	std::cin>> N;
	vector<int> A(N);

	for (int i = 0; i < N;i++) {
		std::cin >> A[i];
	}

	int cnt=0;
	for (int i = 0; i < N;i++) {
		if (prime_number(A[i])==true)
			cnt++;
	}

	std::cout << cnt;
	return 0;
}

bool prime_number(int n) {
	if (n <2)							// 0,1�� �Ҽ� �ƴ�
		return false;
	for (int i = 2; i * i <= n; i++) {  // ��n������
		if (n % i == 0) return false;	// 2�̻��� ����� ������ �Ҽ� �ƴ�
	}
	return true;		
}