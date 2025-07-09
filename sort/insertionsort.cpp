#include <iostream>
#include <vector>
using namespace std;

int main(void) {					// 백준 24053 삽입정렬
	ios::sync_with_stdio(false);  // C와의 동기화 해제
	cin.tie(NULL);                // cin과 cout의 묶음을 해제
	int N;

	cin >> N;
	vector<int> A1(N);
	vector<int> A2(N);

	for (int i = 0; i < N; i++) {
		cin >> A1[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> A2[i];
	}

	for (int i = 1; i < N;i++) {
		int newItem = A1[i];
		int loc = i - 1;
		while (loc >= 0 && A1[loc] > newItem) {							// 계속 원소들을 밀고
			A1[loc + 1] = A1[loc];
			if (A1[loc] == A2[loc] && A1[loc + 1] == A2[loc + 1]) {
				if (A1 == A2) {
					cout << 1;
					return 0;
				}
			}
			loc--;
		}
		if (loc != i - 1) {												// 마지막에 바꾸어 준다
			A1[loc + 1] = newItem;
			if (A1[loc+1] == A2[loc+1] && A1[loc + 2] == A2[loc + 2]) {
				if (A1 == A2) {
					cout << 1;
					return 0;
				}
			}
		};
	}

	cout << 0;
	return 0;

}
