#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);  // C I/O ���� ���
    cin.tie(NULL);                // cin/cout �и� (����� �ӵ� ����)

    int T;                        // �׽�Ʈ ���̽� ����
    cin >> T;
    string result = "";           // ��ü ��� ����� ������ ���ڿ�

    while (T--) {                 // �׽�Ʈ ���̽����� �ݺ�
        int N;
        cin >> N;

        // multiset: �ڵ� ������ �Ǵ� �����̳�
        // greater<int>: �������� ���� �� begin()�� �ִ밪, end()�� �ּҰ�
        multiset<int, greater<int>> mts;

        for (int i = 0; i < N; i++) {
            char c;               // ���� ���� ('I' �Ǵ� 'D')
            int n;                // ���꿡 ���̴� ����
            cin >> c >> n;

            if (c == 'I') {
                // "I n" �� n�� ����
                mts.insert(n);
            }
            else if (c == 'D' && !mts.empty()) {
                // "D 1" �� �ִ밪 ����
                if (n == 1)
                    mts.erase(mts.begin());
                // "D -1" �� �ּҰ� ����
                else if (n == -1)
                    mts.erase(prev(mts.end()));  // end()�� ������ ������ ������ ����Ű�Ƿ�, prev() �ʿ�
            }
        }

        // ���� ���� �� ��� ����
        if (mts.empty()) {
            // ť�� ������� EMPTY
            result += "EMPTY\n";
        }
        else {
            // ť�� ������� ������ �ִ밪�� �ּҰ� ���
            result += to_string(*mts.begin()) + ' ' + to_string(*prev(mts.end())) + '\n';
        }
    }

    cout << result;  // ��� ��� �� ���� ���
    return 0;
}
