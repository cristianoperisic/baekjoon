#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using std::vector;
using std::string;

int main(void) {
	string s;
	std::cin >> s;  // 수식을 문자열로 입력받음 (예: 55-50+40)

	vector<char> A(s.begin(), s.end());  // 문자열 → 문자 벡터로 변환

	int n = 0;
	// 첫 '-'가 등장한 이후 모든 '+'를 '-'로 바꾸기 위한 처리
	for (int i = 0; i < A.size(); i++) {
		if (n == 0 && A[i] == '-')
			n++;  // 최초 '-' 만났을 때 n = 1로 설정
		else if (n == 1 && A[i] == '+')
			A[i] = '-';  // 이후 '+'는 '-'로 변경 (괄호 넣은 효과)
	}

	// 앞에 불필요한 '0' 제거 (문자열이 '000123'처럼 시작할 경우)
	while (A[0] == '0')
		A.erase(A.begin());

	// 연산자 다음에 오는 '0' 제거 (예: -012 → -12)
	for (int i = 1; i < A.size(); i++) {
		if (A[i] == '0' && (A[i - 1] == '-' || A[i - 1] == '+')) {
			A.erase(A.begin() + i);
			i--;  // erase로 인덱스 줄었으므로 한 칸 되돌림
		}
	}

	// 다시 문자 벡터를 문자열로 결합
	string b(A.begin(), A.end());
	vector<int> myVector;  // 파싱된 정수들을 저장할 벡터

	// 문자열을 순회하면서 연산자 기준으로 정수 추출
	for (int i = 1; i <= b.size(); i++) {
		if (b[i] == '-' || b[i] == '+') {
			string k = "";
			for (int j = 0; j < i; j++) k += b[j];  // 앞부분 잘라서
			b.erase(b.begin(), b.begin() + i);     // b에서 제거하고
			myVector.push_back(stoi(k));           // 정수로 변환해 저장
			i = i - k.size() + 1;  // i 초기화 (b 줄어들었으므로 보정)
		}
		if (b[i] == '\0') {  // 문자열 마지막 처리
			string k = "";
			for (int j = 0; j < i; j++) k += b[j];
			myVector.push_back(stoi(k));
			break;
		}
	}

	int sum = 0;
	for (int i = 0; i < myVector.size(); i++) {
		sum += myVector[i];  // 최종적으로 정수들을 모두 더함
	}

	std::cout << sum;  // 결과 출력
	return 0;
}
