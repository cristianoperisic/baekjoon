#include <iostream>
#include <map>

using namespace std;

map<char, int> dirs = {{'E', 0}, {'W', 1}, {'S', 2}, {'N', 3}};
int dr[4] = {0, 0, 1, -1}; // E W S N
int dc[4] = {1, -1, 0, 0};
int r_start = 0, c_start = 0;

int N;
char dir[100];
int dist[100];

int main()
{
    int cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> dir[i] >> dist[i];
    }

    int r = r_start, c = c_start;

    for (int i = 0; i < N; i++)
    {
        int realDir = dirs[dir[i]];       // 방향
        for (int j = 0; j < dist[i]; j++) // 횟수
        {
            r += dr[realDir];
            c += dc[realDir];
            cnt++;
            if (r == r_start && c == c_start)
            {
                cout << cnt << '\n';
                return 0;
            }
        }
    }

    cout << -1 << "\n";

    return 0;
}