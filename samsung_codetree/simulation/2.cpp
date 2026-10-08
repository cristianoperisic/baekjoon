#include <iostream>

using namespace std;
void rotate_once();

int n, t;
int l[200];
int r[200];
int d[200];

int tmp1 = 0, tmp2 = 0, tmp3 = 0;

int main()
{
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> l[i];

    for (int i = 0; i < n; i++)
        cin >> r[i];

    for (int i = 0; i < n; i++)
        cin >> d[i];

    t = t % (3 * n);

    for (int i = 0; i < t; i++)
        rotate_once();

    for (int i = 0; i < n; i++)
        cout << l[i] << " ";

    cout << '\n';

    for (int i = 0; i < n; i++)
        cout << r[i] << " ";

    cout << '\n';

    for (int i = 0; i < n; i++)
        cout << d[i] << " ";

    cout << '\n';

    return 0;
}

void rotate_once()
{
    tmp1 = l[n - 1];
    tmp2 = r[n - 1];
    tmp3 = d[n - 1];

    for (int i = n - 1; i >= 1; i--)
    {
        l[i] = l[i - 1];
        r[i] = r[i - 1];
        d[i] = d[i - 1];
    }

    l[0] = tmp3;
    r[0] = tmp1;
    d[0] = tmp2;
}
