#include <iostream>
#include <map>

bool inRange(int nr, int nc);
void doOnce();

using namespace std;

int dir = 1;               // 처음엔 오른쪽 방향
int dr[4] = {-1, 0, 1, 0}; // 상 우 하 좌
int dc[4] = {0, 1, 0, -1}; // (dir+1)%4 면 시계 방향 (dir+3)%r 이면 반시계 방향

int cnt = 0; // 이동횟수
int N;
int x, y;
char grid[102][102];
bool visited[102][102][4]; // 이미 방문한 곳 방문하면 -1

int main()
{
    cin >> N;
    cin >> x >> y; // 시작 위치

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> grid[i][j];
        }
    }
    while (true)
    {
        if (visited[x][y][dir])
        {
            cnt = -1;
            break;
        }
        visited[x][y][dir] = true;
        doOnce();
        if (grid[x][y] == 0)
            break;
    }

    cout << cnt << '\n';
    return 0;
}

void doOnce() // 주요 로직
{
    if (grid[x + dr[(dir + 1) % 4]][y + dc[(dir + 1) % 4]] == '#') // 바라보는 방향 기준 오른쪽에 벽이 있다
    {
        if (grid[x + dr[dir]][y + dc[dir]] == '#') // 벽 있으면 왼쪽으로 돌기
            dir = (dir + 3) % 4;
        else // 벽 없으면 전진
        {
            x += dr[dir];
            y += dc[dir];
            cnt++;
        }
    }
    else // 바라보는 방향 기준 오른쪽에 벽이 없다
    {
        dir = (dir + 1) % 4;
        x += dr[dir];
        y += dc[dir];
        cnt++;
    }
}

bool inRange(int nr, int nc)
{
    return (nr > 0 && nr <= N && nc > 0 && nc <= N);
}