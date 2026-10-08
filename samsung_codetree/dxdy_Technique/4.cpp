#include <iostream>
#include <map>

using namespace std;
bool inRange(int x, int y);

int n, t; // 격자 수, 시간
int r, c; // 초기 좌표
char d;   // 초기 방향
map<char, int> dirIdx = {{'L', 0}, {'D', 1}, {'R', 2}, {'U', 3}};

int dr[4] = {0, 1, 0, -1}; // L D R U
int dc[4] = {-1, 0, 1, 0};

int main()
{
    cin >> n >> t;
    cin >> r >> c >> d;
    int realDir = dirIdx[d];

    while (t--)
    {
        int nr = r + dr[realDir];
        int nc = c + dc[realDir];
        if (!inRange(nr, nc))
        {
            realDir = (realDir + 2) % 4;
        }
        else
        {
            r = nr;
            c = nc;
        }
    }

    cout << r << " " << c << '\n';
}

bool inRange(int x, int y) // 문제 조건에선 위배될 일이 없긴 함
{
    return (x > 0 && x <= n && y > 0 && y <= n);
}