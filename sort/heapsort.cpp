#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;        // ���� 24174 �� ����2

int K = 0;     // ��ǥ�� �ϴ� K��° swap
int cnt = 0;   // ������� �߻��� swap Ƚ��

// heapify �Լ�: A[k]�� ��Ʈ�� �ϴ� Ʈ���� �ּ� �� ������ �����ϵ��� ����
void heapify(vector<int>& A, int k, int n) {
    int left = 2 * k + 1;       // ���� �ڽ� �ε���
    int right = 2 * k + 2;      // ������ �ڽ� �ε���
    int smaller = k;           // ���� ���� ���� ���� ����� �ε��� �ʱ�ȭ

    // �ڽ� ��尡 �� �� �ִ� ���
    if (right <= n - 1) {
        smaller = (A[left] < A[right]) ? left : right;
    }
    // ���� �ڽĸ� �ִ� ���
    else if (left <= n - 1) {
        smaller = left;
    }

    // �ּ� �� ������ �������� ������ swap ����
    if (smaller != k && A[smaller] < A[k]) {
        swap(A[k], A[smaller]);   // ��ȯ �߻�
        cnt++;                    // swap Ƚ�� ����

        // K��° swap ������ �迭 ��� �� ����
        if (cnt == K) {
            for (auto x : A) cout << x << ' ';
            return;
        }

        // ��������� �ڽ� ����Ʈ���� ���� heapify
        heapify(A, smaller, n);
    }
}

// �ּ� �� ����: �迭�� �߰����� ��Ʈ���� heapify ����
void build_min_heap(vector<int>& A, int n) {
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapify(A, i, n);
    }
}

// �� ���� �Լ�
void heap_sort(vector<int>& A, int n) {
    build_min_heap(A, n);  // ���� �ּ� �� ����

    // ���� ����: ���� ���� ���� �ڷ� ������ �ݺ�
    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);  // ��Ʈ(A[0])�� �� �� A[i] ��ȯ
        cnt++;             // swap Ƚ�� ����

        // K��° swap�̸� ��� �� ����
        if (cnt == K) {
            for (auto x : A) cout << x << ' ';
            return;
        }

        // ���ҵ� �������� �ٽ� heapify ����
        heapify(A, 0, i);
    }
}

int main(void) {
    int N;
    cin >> N >> K;
    vector<int> A(N);

    // �迭 �Է�
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // �� ���� ����
    heap_sort(A, N);

    // ���� K��° swap�� ������ �Ͼ�� �ʾҴٸ� -1 ���
    if (cnt < K) {
        cout << -1;
    }

    return 0;
}
