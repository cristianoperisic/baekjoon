#include <iostream>

using namespace std;
void chooseDir(int n, int k);
void step();
bool inRange(int r, int c);

int n;
char grid[1000][1000];
int k;

int dr[4] = {0, 0, 1, -1}; // 동 서 남 북
int dc[4] = {1, -1, 0, 0};
int r = 0, c = 0; // 좌표
int dir = 0;      // 머리방향
int cnt = 0;      // 출력

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cin >> k;
    chooseDir(n, k); // 방향과 초기좌표 초기화

    while (inRange(r, c))
    {
        step();
        r += dr[dir];
        c += dc[dir];
        cnt++;
    }

    cout << cnt << '\n';
    return 0;
}

void chooseDir(int n, int k)
{
    if (k >= 1 && k <= n)
    {
        r = 0;
        c = (k - 1) % n;
        dir = 2;
    }
    else if (k >= n + 1 && k <= 2 * n)
    {
        r = (k - 1) % n;
        c = n - 1;
        dir = 1;
    }
    else if (k >= 2 * n + 1 && k <= 3 * n)
    {
        r = n - 1;
        c = ((5 * n + 1 - k) - 1) % n;
        dir = 3;
    }
    else if (k >= 3 * n + 1 && k <= 4 * n)
    {
        r = ((7 * n + 1 - k) - 1) % n;
        c = 0;
        dir = 0;
    }
}

void step() // 현 좌표, 머리방향, 슬래시
{
    if (dir == 0) // 동
    {
        dir = (grid[r][c] == '/') ? 3 : 2;
    }
    else if (dir == 1) // 서
    {
        dir = (grid[r][c] == '/') ? 2 : 3;
    }
    else if (dir == 2) // 남
    {
        dir = (grid[r][c] == '/') ? 1 : 0;
    }
    else if (dir == 3) // 북
    {
        dir = (grid[r][c] == '/') ? 0 : 1;
    }
}

bool inRange(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < n);
}