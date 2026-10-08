#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool inRange(int nr, int nc);
bool canGo(int nr, int nc);
void Push(int nr, int nc);
void BFS();
pair<int, int> findMax();

int dr[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dc[4] = {0, 0, -1, 1};

int n, k;
int grid[101][101];
int canVisit[101][101]; // 갈 수 있는 곳을 나타내는 행렬
queue<pair<int, int>> q;
int r, c;
int cur;

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    for (int i = 0; i < k; i++)
    {
        Push(r, c);
        cur = grid[r][c];
        BFS();

        pair<int, int> temp = findMax();
        if (temp.first == -1)
            break;
        r = temp.first;
        c = temp.second;

        memset(canVisit, 0, sizeof(canVisit));
    }

    cout << r << ' ' << c << '\n';
    return 0;
}

void Push(int nr, int nc)
{
    canVisit[nr][nc] = 1;
    q.push(make_pair(nr, nc));
}

void BFS()
{ // 갈 수 있는 canVisit 행렬을 만드는 과정
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

            if (canGo(nr, nc))
                Push(nr, nc);
        }
    }
}

pair<int, int> findMax()
{                               // canVisit에서 최댓값인 r,c 찾는 것
    int max_r = -1, max_c = -1; // 이동 안하면 멈춰야함

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (canVisit[i][j] == 1 && max < grid[i][j] && !(i == r && j == c)) // 출발점도 제외
            {
                max = grid[i][j];
                max_r = i;
                max_c = j;
            }
        }
    }

    return make_pair(max_r, max_c);
}

bool canGo(int nr, int nc)
{
    if (!inRange(nr, nc))
        return false;

    if (grid[nr][nc] >= cur || canVisit[nr][nc] == 1)
        return false;
    else
        return true;
}
bool inRange(int nr, int nc)
{
    return (nr > 0 && nr <= n && nc > 0 && nc <= n);
}