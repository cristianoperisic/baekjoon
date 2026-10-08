#include <iostream>

using namespace std;

int n;                     // n은 1부터 100까지의 수
int grid[102][102];        // 전역 변수로 선언하면 다 0으로 채워짐
int dx[4] = {1, -1, 0, 0}; // 동서남북
int dy[4] = {0, 0, -1, 1};
int cnt = 0;

int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    } // 기본 격자 채우기

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ncnt = 0;
            int x = i, y = j; // 기준 좌표
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];    // 상하좌우 좌표
                if (grid[nx][ny] == 1) // 1이 채워있으면
                    ncnt++;            // ncnt 1올리기
            }
            if (ncnt >= 3)
                cnt += 1; // ncnt가 3이상인 좌표
        }
    }

    cout << cnt << "\n";

    return 0;
}