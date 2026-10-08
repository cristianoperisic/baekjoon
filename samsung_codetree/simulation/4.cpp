#include <iostream>
#include <cstring>

using namespace std;

int n;
int blocks[100];
int temp[100];
int s1, e1;
int s2, e2;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2; // 기본 입력

    int n_start = n;
    n = n - (e1 - s1 + 1); // 원소 수

    for (int i = s1 - 1; i < e1; i++)
    {
        blocks[i] = 0;
    }

    int blocksIdx = 0; // 약간 이터레이터 같은
    for (int i = 0; i < n; i++)
    {
        while (blocks[blocksIdx] == 0 && blocksIdx < n_start)
            blocksIdx++;
        temp[i] = blocks[blocksIdx];
        blocksIdx++; // 여기 근데 범위 넘어갈 수도 있긴 함.
    }
    memcpy(blocks, temp, sizeof(temp));
    memset(temp, 0, sizeof(temp));

    n = n - (e2 - s2 + 1);

    for (int i = s2 - 1; i < e2; i++)
    {
        blocks[i] = 0;
    }

    blocksIdx = 0;
    for (int i = 0; i < n; i++)
    {
        while (blocks[blocksIdx] == 0 && blocksIdx < n_start)
            blocksIdx++;
        temp[i] = blocks[blocksIdx];
        blocksIdx++;
    }
    memcpy(blocks, temp, sizeof(temp));

    cout << n << '\n';

    for (int i = 0; i < n; i++)
    {
        cout << blocks[i] << '\n';
    }

    return 0;
}
