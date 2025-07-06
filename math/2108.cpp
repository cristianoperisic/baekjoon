#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int main(void) {								// 백준 2108 통계학, 최빈값이 좀 어려움
	int N;
	cin >> N;

	vector<int> taehwan(N);
	for (int i = 0; i < N;i++) {
		cin >> taehwan[i];
	}

	sort(taehwan.begin(), taehwan.end()); // 오름차순 정렬 완료		// sort(v.시작, v.마지막다음, 비교자)

	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += taehwan[i];			      // 합 완료, N으로 나누어서 산술평균
	}

	int center = taehwan[N / 2 ];	  // 중앙값
	int max = *max_element(taehwan.begin(), taehwan.end()); // 최대, 정렬했으니 그냥 맨 뒤에꺼 해도 될듯
	int min = *min_element(taehwan.begin(), taehwan.end()); // 최소, 역시 맨앞 해도 ㄱㅊ

	vector<pair<int, int>> A;							// 최빈값 찾기 위해 <int, int> 벡터 생성, first는 값, second는 빈도로 할 것 
	A.push_back({ taehwan[0],1 });							// 맨앞에 taehwan[0]을 넣고 횟수 1넣음

	for (int i = 1; i < N;i++) {
		if (taehwan[i - 1] != taehwan[i]) {					// 이전과 값이 다르면	
			A.push_back({ taehwan[i],1 });					// 새롭게 추가
		}
		else {
			A[A.size() - 1].second++;					// 아니면 빈도수+1
		}

	}
	sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {	// second의 크기로 정렬(내림차순), 람다 함수를 사용
		return a.second > b.second;
		});
	
	// A: {값, 빈도} 쌍들을 빈도 기준으로 내림차순 정렬한 상태

	int many;
	if (A.size() == 1 || A[0].second != A[1].second) {		// 벡터 크기 0이거나 최빈값이 하나라면
		many = A[0].first;					// 그게 최빈값
	}
	else {
		many = A[1].first;  // 두 번째로 작은 최빈값		// 아니면 두번째로 작은 것이 최빈값(문제조건)
	}



	cout << static_cast<int>(round(sum / N)) << '\n' << center << '\n' << many << '\n' << max - min;

		// c++ 스타일 형변환 static_cast<자료형>()
	return 0;

}
