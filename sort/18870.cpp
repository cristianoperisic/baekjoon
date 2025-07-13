#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);  // 입출력 속도 향상
	cin.tie(NULL);

	int N;
	cin >> N;
	
	// set<int> ; set으로 하려했으나 실패
	vector<int> v1(N);// 실제 값
	vector<int> sorted;

	for (int i = 0;i < N;i++) {
		cin >> v1[i];
		sorted.push_back(v1[i]);
	}
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());	
	// unique는 중복을 제거한 것의 다음 iterator 반환~끝 부분 삭제 
	// 좌표 압축에서 이게 set- distance이용보다 더 빠름
	for (int i = 0;i < N;i++) {
		int idx = lower_bound(sorted.begin(), sorted.end(), v1[i]) - sorted.begin();
		cout << idx << ' ';
	}


	return 0;
}