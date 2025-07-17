#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;								// ���� 2042��

int main(void) {
	int N, M, K; // N: ���� ����, M: ���� Ƚ��, K: ������ ���ϴ� Ƚ��
	cin >> N >> M >> K;
	vector<long long> A(N + 1); // ���� ���� (1-based indexing)
	vector<long long> B(N + 1); // ������ �迭
	string result = "";

	// ���� �Է¹ް� ������ B ���
	for (int i = 1;i <= N;i++) {
		cin >> A[i];
		B[i] += A[i] + B[i - 1];
	}

	map<long long, long long> C; // ����� ������ ���̸� ����ϴ� map (index -> delta)

	for (int i = 0;i < M + K;i++) {
		long long a, b, c;
		long long cnt = 0;
		long long sum = 0;
		cin >> a >> b >> c;

		if (a == 1) {
			// A[b]�� c�� �ٲٴ� ��� �� ��ȭ���� ����
			C[b] = c - A[b];
		}
		else if (a == 2) {
			// ���� [b, c]�� ���� ���ϴ� ���
			// ��ȭ���� �����ϴ� index�� �����տ� ������
			if (!C.empty()) {
				for (auto pair : C) {
					if (b <= pair.first && c >= pair.first)
						cnt += pair.second; // ��ȭ�� ����
				}
			}
			sum += B[c] - B[b - 1] + cnt; // ������ + ��ȭ��
			result += to_string(sum) + '\n';
		}
	}

	cout << result; // ��� ��� ���
	return 0;
}
