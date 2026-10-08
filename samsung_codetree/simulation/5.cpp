#include <iostream>
#include <cstring>

using namespace std;
void make2048(char dir);

int grid[4][4];
char dir;
int temp[4][4]; // 임시 저장 배열

int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> grid[i][j];
        }
    }

    cin >> dir;

    make2048(dir);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

void make2048(char dir)
{
    int pnt; // 실제 배열에서 가리키고 잇는 부분

    if (dir == 'R')
    {
        for (int i = 0; i < 4; i++) // 오른쪽으로 다 미는 로직
        {                           // temp 배열 자리라고 생각하면 됨
            pnt = 3;
            for (int j = 3; j >= 0; j--)
                if (grid[i][j] != 0)
                    temp[i][pnt--] = grid[i][j];

            // temp에는 pnt+1번째 열까지 원소 있음

            for (int j = 0; j < 4; j++)
                grid[i][j] = 0; // 그 행 비우기

            int r = 3, w = 3; // r은 tmp에서 읽는 부분 w는 grid에 쓰는 부분

            while (r > pnt)
            {
                if (r - 1 > pnt && temp[i][r] == temp[i][r - 1])
                {
                    grid[i][w--] = temp[i][r] * 2;
                    r -= 2;
                }
                else
                {
                    grid[i][w--] = temp[i][r];
                    r--;
                }
            }
        }
    }
    else if (dir == 'L')
    {
        for (int i = 0; i < 4; i++) // 왼쪽으로 다 미는 로직
        {                           // temp 배열 자리라고 생각하면 됨
            pnt = 0;
            for (int j = 0; j < 4; j++)
                if (grid[i][j] != 0)
                    temp[i][pnt++] = grid[i][j];

            // pnt에는 temp i행의 원소 수 담겨있음

            for (int j = 0; j < 4; j++)
                grid[i][j] = 0; // 그 행 비우기

            int r = 0, w = 0;

            while (r < pnt)
            {
                if (r + 1 < pnt && temp[i][r] == temp[i][r + 1])
                {
                    grid[i][w++] = temp[i][r] * 2;
                    r += 2;
                }
                else
                {
                    grid[i][w++] = temp[i][r];
                    r++;
                }
            }
        }
    }
    else if (dir == 'D')
    {
        for (int j = 0; j < 4; j++) // 아래로 다 미는 로직 j열에 대해
        {                           // temp 배열 자리라고 생각하면 됨
            pnt = 3;
            for (int i = 3; i >= 0; i--)
                if (grid[i][j] != 0)
                    temp[pnt--][j] = grid[i][j];

            for (int i = 3; i >= 0; i--)
                grid[i][j] = 0; // 그 행 비우기

            int r = 3, w = 3;

            while (r > pnt)
            {
                if (r - 1 > pnt && temp[r][j] == temp[r - 1][j])
                {
                    grid[w--][j] = temp[r][j] * 2;
                    r -= 2;
                }
                else
                {
                    grid[w--][j] = temp[r][j];
                    r--;
                }
            }
        }
    }
    else if (dir == 'U')
    {
        for (int j = 0; j < 4; j++) // 위로 다 미는 로직 j열에 대해
        {                           // temp 배열 자리라고 생각하면 됨
            pnt = 0;
            for (int i = 0; i < 4; i++)
                if (grid[i][j] != 0)
                    temp[pnt++][j] = grid[i][j];

            // pnt에는 temp i행의 원소 수 담겨있음

            for (int i = 0; i < 4; i++)
                grid[i][j] = 0; // 그 행 비우기

            int r = 0, w = 0;

            while (r < pnt)
            {
                if (r + 1 < pnt && temp[r][j] == temp[r + 1][j])
                {
                    grid[w++][j] = temp[r][j] * 2;
                    r += 2;
                }
                else
                {
                    grid[w++][j] = temp[r][j];
                    r++;
                }
            }
        }
    }
}