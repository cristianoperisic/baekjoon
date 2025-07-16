#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;  // ǥ�� ���̺귯�� ���

int main(void) {
    int N, M;
    cin >> N >> M;  // �赵 ���� ��� �� N, ���� ���� ��� �� M �Է�

    map<string, int> m;  // �̸��� ���� Ƚ�� ����
    for (int i = 0; i < N + M; i++) {
        string s;
        cin >> s;
        m[s]++;  // �̸��� �����ϸ� ī��Ʈ ����
    }

    // map�� ������ vector<pair<string, int>>�� ��ȯ (������ ����)
    vector<pair<string, int>> v(m.begin(), m.end());

    // ���� Ƚ���� ū ������� ���� (��������)
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });

    // ���� Ƚ���� 2�� ��츸 ���� (��+�� ��� ������ �̸�)
    int i = 0;
    while (i < v.size() && v[i].second == 2) {
        i++;
    }

    v.resize(i);  // v ���Ϳ��� ���� Ƚ���� 2�� �͸� ����

    // ������ ����
    sort(v.begin(), v.end());

    // ��� ���
    cout << v.size() << '\n';  // �躸�� �� ���
    for (auto& p : v)
        cout << p.first << '\n';  // �̸� ���

    return 0;
}
