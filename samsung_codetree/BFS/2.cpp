#include <iostream>
#include <queue>

bool inRange(int nr, int nc);
bool CanGo(int nr, int nc);
void Push(int nr, int nc);
void BFS();

using namespace std;

int dr[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dc[4] = {0, 0, -1, 1};

int n, k;
int grid[101][101];
bool visited[101][101];
int r[10001], c[10001];
queue<pair<int, int>> q;

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];

    for (int i = 1; i <= k; i++)
        cin >> r[i] >> c[i];

    // Please write your code here.

    for (int i = 1; i <= k; i++)
    {
        Push(r[i], c[i]);
        BFS();
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j] == 1)
                cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}

void Push(int nr, int nc)
{
    visited[nr][nc] = true;
    q.push(make_pair(nr, nc));
}

void BFS()
{
    while (!q.empty())
    {
        pair<int, int> curr_v = q.front();
        q.pop();
        int c_r = curr_v.first;
        int c_c = curr_v.second;

        for (int i = 0; i < 4; i++)
        {
            int nr = c_r + dr[i];
            int nc = c_c + dc[i];

            if (CanGo(nr, nc))
                Push(nr, nc);
        }
    }
}

bool CanGo(int nr, int nc)
{
    if (!inRange(nr, nc))
        return false;

    if (visited[nr][nc] == 1 || grid[nr][nc] == 1)
        return false;
    else
        return true;
}

bool inRange(int nr, int nc)
{
    return (nr > 0 && nr <= n && nc > 0 && nc <= n);
}