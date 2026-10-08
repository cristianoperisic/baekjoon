#include <iostream>
#include <queue>

bool inRange(int nr, int nc);
bool CanGo(int nr, int nc);
void Push(int r, int c);
void BFS();
using namespace std;

int dr[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dc[4] = {0, 0, -1, 1};

int n, m;
int a[101][101];         // 길 배열
bool visited[101][101];  // 방문 여부
queue<pair<int, int>> q; // 큐

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) // 실제 행,열 기준으로
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    Push(1, 1);
    BFS();

    if (visited[n][m] == true)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}

void Push(int r, int c)
{
    visited[r][c] = true;
    q.push(make_pair(r, c));
}

void BFS()
{
    while (!q.empty())
    {
        pair<int, int> curr_v = q.front();
        q.pop();

        int r = curr_v.first;
        int c = curr_v.second;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (CanGo(nr, nc))
            {
                Push(nr, nc);
            }
        }
    }
}

bool CanGo(int nr, int nc)
{ // 갈 수 있는 곳인가?
    if (!inRange(nr, nc))
        return false;

    if (a[nr][nc] == 0 || visited[nr][nc]) // 뱀이 있거나 이미 방문했거나
    {
        return false;
    }
    else
        return true;
}

bool inRange(int nr, int nc)
{ // nr, nc가 N X M 안에 있는가?
    return (nr > 0 && nr <= n && nc > 0 && nc <= m);
}
