#include <iostream>
#include <string>

void direction(char c);
using namespace std;
int dx[4] = {0, -1, 0, 1}; // 반시계, 북서남동
int dy[4] = {1, 0, -1, 0};

int dir = 0;      // N방향
int x = 0, y = 0; // 좌표
string dirs;

int main()
{
    cin >> dirs;
    int n = dirs.size();
    for (int i = 0; i < n; i++)
    {
        direction(dirs[i]);
    }

    cout << x << " " << y << "\n";

    return 0;
}

void direction(char c)
{
    if (c == 'L')
    {
        dir = (dir + 1) % 4;
    }
    else if (c == 'R')
    {
        dir = (dir + 3) % 4;
    }
    else if (c == 'F')
    {
        x += dx[dir];
        y += dy[dir];
    }
}