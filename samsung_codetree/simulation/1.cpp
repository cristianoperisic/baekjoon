#include <iostream>

using namespace std;
void rotate_once();

int n, t;
int u[200];
int d[200];             // 0으로 초기화된 u,d
int tmp1 = 0, tmp2 = 0; // u,d 배열 마지막 저장할 곳

int main()
{
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> u[i];

    for (int i = 0; i < n; i++)
        cin >> d[i];

    t = t % (2 * n);

    for (int i = 0; i < t; i++)
        rotate_once();

    for (int i = 0; i < n; i++)
        cout << u[i] << ' ';

    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << d[i] << ' ';

    cout << "\n";
    return 0;
}

void rotate_once()
{
    tmp1 = u[n - 1];
    tmp2 = d[n - 1];
    for (int i = n - 1; i >= 1; i--)
    {
        u[i] = u[i - 1];
        d[i] = d[i - 1];
    }
    u[0] = tmp2;
    d[0] = tmp1;
}
