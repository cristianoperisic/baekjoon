#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;        // 백준 24174 힙 정렬2

int K = 0;     // 목표로 하는 K번째 swap
int cnt = 0;   // 현재까지 발생한 swap 횟수

// heapify 함수: A[k]를 루트로 하는 트리가 최소 힙 성질을 만족하도록 수정
void heapify(vector<int>& A, int k, int n) {
    int left = 2 * k + 1;       // 왼쪽 자식 인덱스
    int right = 2 * k + 2;      // 오른쪽 자식 인덱스
    int smaller = k;           // 가장 작은 값을 가진 노드의 인덱스 초기화

    // 자식 노드가 둘 다 있는 경우
    if (right <= n - 1) {
        smaller = (A[left] < A[right]) ? left : right;
    }
    // 왼쪽 자식만 있는 경우
    else if (left <= n - 1) {
        smaller = left;
    }

    // 최소 힙 조건을 만족하지 않으면 swap 수행
    if (smaller != k && A[smaller] < A[k]) {
        swap(A[k], A[smaller]);   // 교환 발생
        cnt++;                    // swap 횟수 증가

        // K번째 swap 시점에 배열 출력 후 종료
        if (cnt == K) {
            for (auto x : A) cout << x << ' ';
            return;
        }

        // 재귀적으로 자식 서브트리에 대해 heapify
        heapify(A, smaller, n);
    }
}

// 최소 힙 생성: 배열의 중간부터 루트까지 heapify 수행
void build_min_heap(vector<int>& A, int n) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapify(A, i, n);
    }
}

// 힙 정렬 함수
void heap_sort(vector<int>& A, int n) {
    build_min_heap(A, n);  // 먼저 최소 힙 구성

    // 정렬 시작: 가장 작은 값을 뒤로 보내며 반복
    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);  // 루트(A[0])와 맨 끝 A[i] 교환
        cnt++;             // swap 횟수 증가

        // K번째 swap이면 출력 후 종료
        if (cnt == K) {
            for (auto x : A) cout << x << ' ';
            return;
        }

        // 감소된 범위에서 다시 heapify 수행
        heapify(A, 0, i);
    }
}

int main(void) {
    int N;
    cin >> N >> K;
    vector<int> A(N);

    // 배열 입력
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 힙 정렬 수행
    heap_sort(A, N);

    // 만약 K번째 swap이 끝까지 일어나지 않았다면 -1 출력
    if (cnt < K) {
        cout << -1;
    }

    return 0;
}
