#include <iostream>

using namespace std;

void rotate_once(int r1, int c1, int r2, int c2);
void makeAverage(int r1, int c1, int r2, int c2);
bool inRange(int r, int c);

int dr[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dc[4] = {0, 0, -1, 1};

int n, m, q;
int a[100][100];
int tempArr[100][100]; // 임시 저장 배열

int main()
{
    cin >> n >> m >> q;
    int r1, c1, r2, c2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < q; i++)
    {

        cin >> r1 >> c1 >> r2 >> c2;
        rotate_once(r1, c1, r2, c2);
        makeAverage(r1, c1, r2, c2);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}

void rotate_once(int r1, int c1, int r2, int c2)
{
    int tmp1 = a[r1 - 1][c1 - 1];
    int tmp2 = a[r1 - 1][c2 - 1];
    int tmp3 = a[r2 - 1][c2 - 1];
    int tmp4 = a[r2 - 1][c1 - 1];

    for (int i = c2 - 1; i > c1; i--)
    {                                    // 위 행
        a[r1 - 1][i] = a[r1 - 1][i - 1]; // 가장큰게 c2-1, 가장 작은게 c1이 나오도록
    }
    for (int i = r2 - 1; i > r1; i--)
    { // 오른쪽 열
        a[i][c2 - 1] = a[i - 1][c2 - 1];
    }
    for (int i = c1; i < c2 - 1; i++)
    { // 아래 행
        a[r2 - 1][i - 1] = a[r2 - 1][i];
    }
    for (int i = r1; i < r2 - 1; i++)
    { // 왼쪽 열
        a[i - 1][c1 - 1] = a[i][c1 - 1];
    }
    a[r1 - 1][c1] = tmp1; // 임시 저장한거 넣기 까먹지 않기
    a[r1][c2 - 1] = tmp2;
    a[r2 - 1][c2 - 2] = tmp3;
    a[r2 - 2][c1 - 1] = tmp4;
}

void makeAverage(int r1, int c1, int r2, int c2)
{
    int nr, nc;

    for (int i = 0; i < r2 - r1 + 1; i++) // 평균 내서 임시 저장
    {
        for (int j = 0; j < c2 - c1 + 1; j++)
        {
            int sum = a[i + r1 - 1][j + c1 - 1];
            int cnt = 1;
            for (int k = 0; k < 4; k++)
            {
                int nr = i + r1 - 1 + dr[k];
                int nc = j + c1 - 1 + dc[k];
                if (inRange(nr, nc))
                {
                    sum += a[nr][nc];
                    cnt++;
                }
            }
            sum /= cnt;
            tempArr[i][j] = sum;
        }
    }

    for (int i = r1 - 1; i < r2; i++)
    {
        for (int j = c1 - 1; j < c2; j++)
        {
            a[i][j] = tempArr[i - r1 + 1][j - c1 + 1];
        }
    }
}

bool inRange(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}
