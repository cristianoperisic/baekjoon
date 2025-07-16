#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;  // 표준 라이브러리 사용

int main(void) {
    int N, M;
    cin >> N >> M;  // 듣도 못한 사람 수 N, 보도 못한 사람 수 M 입력

    map<string, int> m;  // 이름별 등장 횟수 저장
    for (int i = 0; i < N + M; i++) {
        string s;
        cin >> s;
        m[s]++;  // 이름이 등장하면 카운트 증가
    }

    // map의 내용을 vector<pair<string, int>>로 변환 (정렬을 위해)
    vector<pair<string, int>> v(m.begin(), m.end());

    // 등장 횟수가 큰 순서대로 정렬 (내림차순)
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });

    // 등장 횟수가 2인 경우만 추출 (듣+보 모두 등장한 이름)
    int i = 0;
    while (i < v.size() && v[i].second == 2) {
        i++;
    }

    v.resize(i);  // v 벡터에서 등장 횟수가 2인 것만 남김

    // 사전순 정렬
    sort(v.begin(), v.end());

    // 결과 출력
    cout << v.size() << '\n';  // 듣보잡 수 출력
    for (auto& p : v)
        cout << p.first << '\n';  // 이름 출력

    return 0;
}
