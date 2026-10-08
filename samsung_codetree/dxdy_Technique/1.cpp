#include <iostream>
#include <map>

using namespace std;

map<char, int> dirNum = {{'E', 0}, {'W', 1}, {'S', 2}, {'N', 3}};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1}; // E W S N

int main()
{
    int n, x = 0, y = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        int dist; // N 2
        cin >> c >> dist;
        x += dist * dx[dirNum[c]];
        y += dist * dy[dirNum[c]];
    }
    cout << x << " " << y << '\n';

    return 0;
}