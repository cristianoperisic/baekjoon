#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
/*using namespace std;
using std::vector;

int main(void) {
	int N;
	cin >> N;

	vector<int> taehwan(N);
	for (int i = 0; i < N;i++) {
		cin >> taehwan[i];
	}

	sort(taehwan.begin(), taehwan.end()); // �������� ���� �Ϸ�

	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += taehwan[i];			      // �� �Ϸ�, N���� ����� ������
	}

	int center = taehwan[N / 2 ];	  // �߾Ӱ�
	int max = *max_element(taehwan.begin(), taehwan.end()); // �ִ�, ���������� �׳� �� �ڿ��� �ص� �ɵ�
	int min = *min_element(taehwan.begin(), taehwan.end()); // �ּ�, ���� �Ǿ� �ص� ����

	vector<pair<int, int>> A;								// �ֺ� ã�� ���� <int, int> ���� ����
	A.push_back({ taehwan[0],1 });							// �Ǿտ� taehwan[0]�� �ְ� Ƚ�� 1����

	for (int i = 1; i < N;i++) {
		if (taehwan[i - 1] != taehwan[i]) {
			A.push_back({ taehwan[i],1 });
		}
		else {
			A[A.size() - 1].second++;
		}

	}
	sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {	// second�� ũ��� ����(��������)
		return a.second > b.second;
		});
	
	// A: {��, ��} �ֵ��� �� �������� �������� ������ ����

	int many;
	if (A.size() == 1 || A[0].second != A[1].second) {
		many = A[0].first;
	}
	else {
		many = A[1].first;  // �� ��°�� ���� �ֺ�
	}



	cout << static_cast<int>(round(sum / N)) << '\n' << center << '\n' << many << '\n' << max - min;


	return 0;

}*/