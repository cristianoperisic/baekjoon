#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
using std::vector;

int main(void){						// ���� 11650 ��ǥ �����ϱ�
	int N;
	std::cin >> N;

	vector<pair<int, int>> A(N);	// ���� ����
	
	for (int i = 0; i < N; i++) {
		std::cin >> A[i].first>>A[i].second;//�Է¹ް�
	}

	sort(A.begin(), A.end());		// ���̺귯���� ������ ó��
	for (auto& x : A) {
		cout << x.first << ' ' << x.second << '\n';
	}								// ���

	return 0;
}