#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  // C I/O 성능 향상
    cin.tie(NULL);                // cin/cout 분리 (입출력 속도 개선)

    int T;                        // 테스트 케이스 개수
    cin >> T;
    string result = "";           // 전체 출력 결과를 저장할 문자열

    while (T--) {                 // 테스트 케이스마다 반복
        int N;
        cin >> N;

        // multiset: 자동 정렬이 되는 컨테이너
        // greater<int>: 내림차순 정렬 → begin()이 최대값, end()가 최소값
        multiset<int, greater<int>> mts;

        for (int i = 0; i < N; i++) {
            char c;               // 연산 종류 ('I' 또는 'D')
            int n;                // 연산에 쓰이는 숫자
            cin >> c >> n;

            if (c == 'I') {
                // "I n" → n을 삽입
                mts.insert(n);
            }
            else if (c == 'D' && !mts.empty()) {
                // "D 1" → 최대값 삭제
                if (n == 1)
                    mts.erase(mts.begin());
                // "D -1" → 최소값 삭제
                else if (n == -1)
                    mts.erase(prev(mts.end()));  // end()는 마지막 원소의 다음을 가리키므로, prev() 필요
            }
        }

        // 연산 종료 후 결과 저장
        if (mts.empty()) {
            // 큐가 비었으면 EMPTY
            result += "EMPTY\n";
        }
        else {
            // 큐가 비어있지 않으면 최대값과 최소값 출력
            result += to_string(*mts.begin()) + ' ' + to_string(*prev(mts.end())) + '\n';
        }
    }

    cout << result;  // 모든 결과 한 번에 출력
    return 0;
}
