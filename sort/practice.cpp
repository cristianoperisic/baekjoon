#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
using std::vector;

int main(void){						// 백준 11650 좌표 정렬하기
	int N;
	std::cin >> N;

	vector<pair<int, int>> A(N);	// 벡터 정의
	
	for (int i = 0; i < N; i++) {
		std::cin >> A[i].first>>A[i].second;//입력받고
	}

	sort(A.begin(), A.end());		// 라이브러리로 간단히 처리
	for (auto& x : A) {
		cout << x.first << ' ' << x.second << '\n';
	}								// 출력

	return 0;
}