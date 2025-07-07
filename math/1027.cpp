#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;										// 백준 1027번 고층건물
typedef long long ll;

vector<ll> A1;											    // right left 함수 정의 위해서 벡터를 전역으로 선언 
vector < ll > A2;

ll right(ll, int);
ll left(ll);

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N;i++) {							// 입력 받음
		long long a;
		cin >> a;
		A1.push_back(a);									// 값들을 담는 벡터
		A2.push_back(0);									// 보이는 건물 수 담는 벡터
	}	

	if (N == 1) {											// N==1이면 좌우 확인이 안되니까 예외처리
		cout << 0;
		return 0;
	}
	
	for (ll i = 0;i < N;i++) {								
		if (i == 0) {										// i==0이면 오른쪽만
			A2[i] += right(i, N);
		}
		else if (i == N - 1) {								// i가 끝이면 왼쪽만
			A2[i] += left(i);
		}
		else {
			A2[i] += right(i, N) + left(i);					// 나머지는 좌우 둘 다 확인
		}
	}

	sort(A2.begin(), A2.end());								// 정렬해주고

	cout << A2[static_cast<ll>(N)-1];						// 제일 큰 걸 출력 (형변환도 일단 해줌)

	return 0;
}

long long right(ll i, int N){								 // 본인 위치 인덱스, 개수, i<N
	ll cnt = 0;
	for (ll j = i + 1;j < N;j++) {							 // j는 i 다음부터 N-1인덱스까지 
		if (j == i + 1)										
			cnt++;
		else {
			for (ll k = i + 1; k < j;k++) {					 // j,i 이은 선분 위의 k번째 점과 A1[k]비교
				if ((A1[j] - A1[i]) * (k - i) + A1[i] * (j - i) <= A1[k] * (j - i)) {
					goto exit;								 // A1[k]가 더 크면 안보이니까 goto로 loop빠져나옴
				}
			}
			cnt++;	
		exit:;			
		}
	}

	return cnt;
}

long long left(ll i) {									      // 본인 위치 인덱스
	ll cnt = 0;											
	for (ll j = 0;j < i;j++) {								  // right함수랑 비슷하게 동작
		if (j == i - 1)
			cnt++;
		else {
			for (ll k = j + 1; k < i;k++) {
				if ((A1[j] - A1[i]) * (k - i) + A1[i] * (j - i) >= A1[k] * (j - i)) {	
					goto exit;								  // 근데 여기서 j-i<0이라 부등호 바뀌는데 right랑 같게 했다가 틀리게 나왔었음
				}	
			}
			cnt++;
		exit:;
		}
	}

	return cnt;
}

