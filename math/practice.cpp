#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	
	vector<int> Tv(T);
	for (int i = 0;i < T;i++) {
		cin >> Tv[i];
	}
	vector<long long> A(101);						// ���� 9095, 9461 ���̳��� ���α׷��� 	
	A[0] = 1; A[1] = 2;A[2] = 4;
	for (int i = 3; i < 11;i++) {
		A[i] = A[i - 1] + A[i - 2] + A[i - 3];
	}
	for (int i = 0;i < T;i++) {
		cout << A[Tv[i] - 1] << '\n';
	}

	return 0;
}