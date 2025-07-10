#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int left(vector<pair<pair<int, int>, int>> A, int i);
int right(vector<pair<pair<int, int>, int>> A, int i, int N);

int main(void) {
	int N;
	cin >> N;

	vector<pair<pair<int, int>,int>> A(N);
	
	for(int i =0;i<N;i++){
		cin >> A[i].first.first>>A[i].first.second;
	}

	for (int i = 0;i < N;i++) {
		if (i == 0) {
			A[i].second = right(A, i, N) + 1;
		}
		if (i == N - 1) {
			A[i].second = left(A, i) + 1;
		}
		else {
			A[i].second = right(A, i, N) + left(A, i) + 1;
		}
	}


	for (auto x : A) {
		cout << x.second<<' ';
	}

	return 0;
}

int left(vector<pair<pair<int, int>,int>> A,int i) {
	int n = 0;
	for (int j = 0;j < i;j++) {
		if (A[i].first.first < A[j].first.first && A[i].first.second < A[j].first.second) {
			n++;
		}
	}
	return n;
}
int right(vector<pair<pair<int, int>,int>> A,int i,int N) {
	int n = 0;
	for (int j = i+1;j < N;j++) {
		if (A[i].first.first < A[j].first.first && A[i].first.second < A[j].first.second) {
			n++;
		}
	}
	return n;
}