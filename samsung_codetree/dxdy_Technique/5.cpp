#include <iostream>

using namespace std;
bool inRange(int r, int c);

int dr[4] = {0, 1, 0, -1}; // 동 남 서 북
int dc[4] = {1, 0, -1, 0};
int r = 0, c = 0;
int realIdx = 0;

int n, m;
int arr[100][100]; // 전부 0인 배열

int main()
{
    cin >> n >> m;
    int x = 1;

    for (int i = 0; i < n * m; i++)
    {
        arr[r][c] = x;
        x++;

        int nr = r + dr[realIdx];
        int nc = c + dc[realIdx];
        if (!inRange(nr, nc) || arr[nr][nc] != 0)
        {
            realIdx = (realIdx + 1) % 4;
        }
        r += dr[realIdx];
        c += dc[realIdx];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

bool inRange(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}