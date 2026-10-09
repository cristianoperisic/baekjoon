#include <iostream>
#include <cstring>

using namespace std;
bool BombAndDown();
void rotate90();
bool inRange(int nc, int nr);
void gravity();

int N,
    M, K;
int grid[102][102];
int temp[102][102];
bool isExploded = true;

int main()
{
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < K; i++) // K번 동안
    {
        isExploded = true; // 이거 안 하면 int 한번에 끝남.
        while (isExploded) // 폭발을 했다면
        {
            isExploded = BombAndDown();
        }

        rotate90();
        gravity();
    }

    isExploded = true; // 마지막에도 한번 진행해서 확실하게 폭발시킨다
    while (isExploded)
    {
        isExploded = BombAndDown();
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (grid[i][j] > 0)
                cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}

bool BombAndDown()
{                          // 폭발시키고 내린다
    bool exploded = false; // 폭발이 일어나면 true를
    memset(temp, 0, sizeof(temp));

    int start, end;

    for (int j = 1; j <= N; j++)
    { // 각 열에 대해 수행
        start = 1;

        while (start <= N)
        {
            if (grid[start][j] == 0)
            {
                start++;
                continue;
            }

            int end = start;
            while (end <= N && grid[start][j] == grid[end][j])
            {
                end++;
            }

            if (end - start >= M)
            {
                for (int i = start; i < end; i++)
                {
                    grid[i][j] = 0;
                    exploded = true;
                }
            }
            start = end;
        }

        int r = N, w = N;

        while (r >= 1) // 내리기 로직
        {
            if (grid[r][j] >= 1)
                temp[w--][j] = grid[r][j];
            r--;
        }
    }

    memcpy(grid, temp, sizeof(temp)); // 폭발시키고 내린 다음에 grid에 반영

    return exploded;
}

void gravity()
{
    memset(temp, 0, sizeof(temp));

    for (int j = 1; j <= N; j++)
    {
        int r = N, w = N;
        while (r >= 1) // 내리기 로직
        {
            if (grid[r][j] >= 1)
                temp[w--][j] = grid[r][j];
            r--;
        }
    }

    memcpy(grid, temp, sizeof(temp)); // 폭발시키고 내린 다음에 grid에 반영
}

void rotate90()
{
    memcpy(temp, grid, sizeof(grid)); // temp에 grid 저장

    for (int i = 1; i <= N; i++) // grid에 90도 회전시켜서 저장
    {
        for (int j = 1; j <= N; j++)
        {
            grid[j][N - i + 1] = temp[i][j];
        }
    }

    memset(temp, 0, sizeof(temp));
}

bool inRange(int nc, int nr)
{
    return (nr >= 1 && nr <= N && nr >= 1 && nr <= N);
}