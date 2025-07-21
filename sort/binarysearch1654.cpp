#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long sum1(long long denominator, int K, const vector<int> &A);

int main(void) {
	ios::sync_with_stdio(false);						//1654 랜선자르기
	cin.tie(NULL);

	int K, N;
	cin >> K >> N;
	vector<int> A(K);
	for (int i = 0;i < K;i++) {
		cin >> A[i];
	}

	long long right = *max_element(A.begin(),A.end());
	long long left = 1;
	long long answer = 0;
	while (left <= right) {
		long long middle = (left + right) / 2;			// 이진 탐색
		long long sum = sum1(middle, K, A);

		if (sum >= N) {
			answer = middle;
			left = middle + 1;
		}
		else {
			if (right != 1)
				right = middle - 1;
			else
				right = middle - 2;
		}
	}


	cout << answer;
	return 0;
}

long long sum1(long long denominator,int K, const vector<int> &A) {
	long long sum = 0;
	for (int i = 0;i < K;i++) {
		sum += (long long)A[i] / denominator;
	}
	return sum;
}
