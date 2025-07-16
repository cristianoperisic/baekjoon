#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(void) {										// ���� 9375�� map Ȱ��
	int N;
	cin >> N;
	string str="";
	for (int i = 0; i < N;i++) {
		int K;
		cin >> K;
		vector<pair<string, string>> A(K);
		for (int i = 0; i < K;i++) {
			cin >> A[i].first >> A[i].second;
		}
		map<string, int> m;
		for (int i = 0;i < K;i++)
			m[A[i].second]++;
		int n=1;
		for (auto x:m){									// x�� <string,int> ����
			n *= x.second+1;
		}

		str += to_string(n-1) + '\n';
	}
	
	cout << str;

	return 0;
}
