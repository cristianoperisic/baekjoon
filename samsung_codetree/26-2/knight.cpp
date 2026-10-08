#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
void BFS();
bool canGo(int nc, int nr);
bool inRange(int nc, int nr);

int dr[8] = {2, 2, 1, 1, -1, -1, -2, -2}; // 나이트가 갈 수 있는 모든 방향
int dc[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int n;
int r1, c1, r2, c2;
int visitNum[102][102];
queue<pair<int, int>> q;

int main()
{
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    // Please write your code here.
    memset(visitNum, -1, sizeof(visitNum)); // -1로 전부 초기화
    visitNum[r1][c1] = 0;                   // 시작점은 0으로
    q.push(make_pair(r1, c1));              // q에도 넣어준다.

    BFS();

    cout << visitNum[r2][c2] << '\n';

    return 0;
}

void BFS()
{
    while (!q.empty())
    {
        pair<int, int> curr_v = q.front();
        q.pop();

        int c_r = curr_v.first;
        int c_c = curr_v.second; // q.front의 행과 열

        for (int i = 0; i < 8; i++)
        {
            int nr = c_r + dr[i];
            int nc = c_c + dc[i];

            if (canGo(nc, nr))
            {
                q.push(make_pair(nr, nc));
                visitNum[nr][nc] = visitNum[c_r][c_c] + 1;
            }
        }
    }
}

bool canGo(int nc, int nr)
{
    if (!inRange(nr, nc))
        return false;

    if (visitNum[nr][nc] != -1)
        return false;
    else
        return true;
}

bool inRange(int nc, int nr)
{
    return (nc > 0 && nc <= n && nr > 0 && nr <= n);
}