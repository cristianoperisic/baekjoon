#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;								// 백준 2042번

int main(void) {
	int N, M, K; // N: 수의 개수, M: 변경 횟수, K: 구간합 구하는 횟수
	cin >> N >> M >> K;
	vector<long long> A(N + 1); // 원래 수열 (1-based indexing)
	vector<long long> B(N + 1); // 누적합 배열
	string result = "";

	// 수열 입력받고 누적합 B 계산
	for (int i = 1;i <= N;i++) {
		cin >> A[i];
		B[i] += A[i] + B[i - 1];
	}

	map<long long, long long> C; // 변경된 값들의 차이를 기록하는 map (index -> delta)

	for (int i = 0;i < M + K;i++) {
		long long a, b, c;
		long long cnt = 0;
		long long sum = 0;
		cin >> a >> b >> c;

		if (a == 1) {
			// A[b]를 c로 바꾸는 명령 → 변화량을 저장
			C[b] = c - A[b];
		}
		else if (a == 2) {
			// 구간 [b, c]의 합을 구하는 명령
			// 변화량이 존재하는 index만 누적합에 더해줌
			if (!C.empty()) {
				for (auto pair : C) {
					if (b <= pair.first && c >= pair.first)
						cnt += pair.second; // 변화량 누적
				}
			}
			sum += B[c] - B[b - 1] + cnt; // 누적합 + 변화량
			result += to_string(sum) + '\n';
		}
	}

	cout << result; // 모든 결과 출력
	return 0;
}
