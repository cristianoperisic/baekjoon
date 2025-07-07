#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;										// ���� 1027�� �����ǹ�
typedef long long ll;

vector<ll> A1;											    // right left �Լ� ���� ���ؼ� ���͸� �������� ���� 
vector < ll > A2;

ll right(ll, int);
ll left(ll);

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N;i++) {							// �Է� ����
		long long a;
		cin >> a;
		A1.push_back(a);									// ������ ��� ����
		A2.push_back(0);									// ���̴� �ǹ� �� ��� ����
	}	

	if (N == 1) {											// N==1�̸� �¿� Ȯ���� �ȵǴϱ� ����ó��
		cout << 0;
		return 0;
	}
	
	for (ll i = 0;i < N;i++) {								
		if (i == 0) {										// i==0�̸� �����ʸ�
			A2[i] += right(i, N);
		}
		else if (i == N - 1) {								// i�� ���̸� ���ʸ�
			A2[i] += left(i);
		}
		else {
			A2[i] += right(i, N) + left(i);					// �������� �¿� �� �� Ȯ��
		}
	}

	sort(A2.begin(), A2.end());								// �������ְ�

	cout << A2[static_cast<ll>(N)-1];						// ���� ū �� ��� (����ȯ�� �ϴ� ����)

	return 0;
}

long long right(ll i, int N){								 // ���� ��ġ �ε���, ����, i<N
	ll cnt = 0;
	for (ll j = i + 1;j < N;j++) {							 // j�� i �������� N-1�ε������� 
		if (j == i + 1)										
			cnt++;
		else {
			for (ll k = i + 1; k < j;k++) {					 // j,i ���� ���� ���� k��° ���� A1[k]��
				if ((A1[j] - A1[i]) * (k - i) + A1[i] * (j - i) <= A1[k] * (j - i)) {
					goto exit;								 // A1[k]�� �� ũ�� �Ⱥ��̴ϱ� goto�� loop��������
				}
			}
			cnt++;	
		exit:;			
		}
	}

	return cnt;
}

long long left(ll i) {									      // ���� ��ġ �ε���
	ll cnt = 0;											
	for (ll j = 0;j < i;j++) {								  // right�Լ��� ����ϰ� ����
		if (j == i - 1)
			cnt++;
		else {
			for (ll k = j + 1; k < i;k++) {
				if ((A1[j] - A1[i]) * (k - i) + A1[i] * (j - i) >= A1[k] * (j - i)) {	
					goto exit;								  // �ٵ� ���⼭ j-i<0�̶� �ε�ȣ �ٲ�µ� right�� ���� �ߴٰ� Ʋ���� ���Ծ���
				}	
			}
			cnt++;
		exit:;
		}
	}

	return cnt;
}

