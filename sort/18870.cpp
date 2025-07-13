#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);  // ����� �ӵ� ���
	cin.tie(NULL);

	int N;
	cin >> N;
	
	// set<int> ; set���� �Ϸ������� ����
	vector<int> v1(N);// ���� ��
	vector<int> sorted;

	for (int i = 0;i < N;i++) {
		cin >> v1[i];
		sorted.push_back(v1[i]);
	}
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());	
	// unique�� �ߺ��� ������ ���� ���� iterator ��ȯ~�� �κ� ���� 
	// ��ǥ ���࿡�� �̰� set- distance�̿뺸�� �� ����
	for (int i = 0;i < N;i++) {
		int idx = lower_bound(sorted.begin(), sorted.end(), v1[i]) - sorted.begin();
		cout << idx << ' ';
	}


	return 0;
}