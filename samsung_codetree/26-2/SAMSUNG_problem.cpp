// =====================================================================
// 코드트리 삼성 기출 | 2026 상반기 오후 1번 · 아기 고래의 첫 항해
// ---------------------------------------------------------------------
// [전체 흐름]
//   while (true)
//     1단계 가능?  → doStep1 : 직진 > 좌회전 > 우회전 > 180도 순으로 한 칸 이동
//     아니면 2단계
//       ① BFS(고래 위치)   : 고래 → 각 칸까지 거리
//       ② findMinOfBFS     : 미방문 바다 중 가장 가까운 칸(타겟) 선택
//                            (동점이면 행 작은 칸 → 열 작은 칸)
//       ③ 타겟이 없으면 종료
//       ④ gotoMinOfBFS     : BFS(타겟)으로 "타겟까지 남은 거리"를 구하고
//                            좌 > 하 > 우 > 상 순으로 거리가 1 줄어드는 칸으로 이동
//
// [디버깅하며 배운 것]
//   1. 회전이 있으면 방향 배열은 시계 방향(상 우 하 좌)으로 둔다.
//   2. BFS에는 반드시 방문 체크. 거리 배열 초기값 규칙은 하나로 통일.
//   3. 종료 조건은 "더 찾을 게 없을 때(-1 반환)"로 판단한다.
//   4. "최단 경로 + 방향 우선순위"는 목표 칸에서 BFS를 한 번 더 돌린다.
//   5. 같은 식이 반복되면 nd, nr, nc 변수로 빼서 오타를 줄인다.
// =====================================================================

#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

// ----- 함수 선언 -----
bool inRange(int nr, int nc);
bool canStep1();
void doStep1();
void BFS(int sr, int sc);
pair<pair<int, int>, int> findMinOfBFS();
void gotoMinOfBFS(pair<pair<int, int>, int> target);
bool canGo(int nr, int nc);
bool inRange(int nr, int nc);

// 입력 방향(1상 2하 3좌 4우) → 배열 인덱스(0상 1우 2하 3좌)로 변환
map<int, int> dToDir = {{1, 0}, {2, 2}, {3, 3}, {4, 1}};

queue<pair<int, int>> q1; // 방문한 순서대로 좌표를 쌓아두는 큐 (마지막에 그대로 출력)
queue<pair<int, int>> q2; // BFS 탐색용 큐

int N, r, c, d; // 격자 크기, 고래 현재 행/열, 고래가 바라보는 방향(배열 인덱스)

// 방향 배열: 시계 방향 순서 (0상 1우 2하 3좌)
//  → (d + 1) % 4 = 우회전, (d + 3) % 4 = 좌회전, (d + 2) % 4 = 180도
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int visited[52][52]; // 고래의 방문 여부  암초: -1 / 미방문: 0 / 방문: 1
int grid[52][52];    // 지도              암초: -1 / 바다: 0
int num_rocks = 0;   // 암초 개수 (최종 코드에서는 사용하지 않음)

// BFS 결과 배열 (grid를 복사해서 사용)
//   -1 : 암초
//    0 : BFS가 아직 도달하지 않은 바다
//   양수: 시작점으로부터의 거리 + 1  (시작점 = 1)
int BFS_arr[52][52];

int main()
{
    cin >> N >> r >> c >> d;

    // 지도 입력 (1-index). 암초(1)는 -1로 바꿔서 저장
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1) // 암초 있으면
            {
                num_rocks++;
                visited[i][j] = -1;
                grid[i][j] = -1;
            }
        }
    }
    d = dToDir[d]; // 입력 방향 → 배열 인덱스

    // 시작 칸도 방문 처리 + 출력 목록에 추가
    q1.push(make_pair(r, c));
    visited[r][c] = 1;

    while (true)
    {
        if (canStep1()) // 1단계: 인접한 미방문 바다가 있으면 한 칸 이동
            doStep1();
        else // 2단계: 가장 가까운 미방문 바다로 이동
        {
            BFS(r, c);                                         // ① 고래 위치에서 BFS
            pair<pair<int, int>, int> target = findMinOfBFS(); // ② 타겟 고르기
            if (target.first.first == -1)                      // ③ 갈 수 있는 미방문 바다가 없음 → 종료
                break;
            gotoMinOfBFS(target); // ④ 타겟으로 이동
        }
    }

    // 방문한 순서대로 좌표 출력
    while (!q1.empty())
    {
        pair<int, int> result_v = q1.front();
        q1.pop();
        cout << result_v.first << ' ' << result_v.second << '\n';
    }

    return 0;
}

// [1단계 가능 여부] 상하좌우 중 "범위 안 + 바다 + 미방문" 칸이 하나라도 있는가
bool canStep1()
{
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (inRange(nr, nc) && grid[nr][nc] == 0 && visited[nr][nc] == 0)
            return true;
    }
    return false;
}

// [1단계] 우선순위대로 한 칸 이동: 직진 > 좌회전 > 우회전 > 180도
//  - 이동한 방향으로 d 갱신, 방문 처리, 출력 목록에 추가
//  - canStep1()이 참일 때만 호출되므로 마지막 else(180도)는 반드시 갈 수 있는 칸
void doStep1()
{
    if (inRange(r + dr[d], c + dc[d]) && grid[r + dr[d]][c + dc[d]] == 0 && visited[r + dr[d]][c + dc[d]] == 0)
    { // 1) 방향 그대로 직진
        r = r + dr[d];
        c = c + dc[d];
        d = d;
        q1.push(make_pair(r, c));
        visited[r][c] = 1;
    }

    else if (inRange(r + dr[(d - 1 + 4) % 4], c + dc[(d - 1 + 4) % 4]) && grid[r + dr[(d - 1 + 4) % 4]][c + dc[(d - 1 + 4) % 4]] == 0 && visited[r + dr[(d - 1 + 4) % 4]][c + dc[(d - 1 + 4) % 4]] == 0)
    { // 2) 좌회전(반시계 90도) 후 직진  ← (d + 3) % 4 와 같음
        r = r + dr[(d - 1 + 4) % 4];
        c = c + dc[(d - 1 + 4) % 4];
        d = (d - 1 + 4) % 4;
        q1.push(make_pair(r, c));
        visited[r][c] = 1;
    }

    else if (inRange(r + dr[(d + 1) % 4], c + dc[(d + 1) % 4]) && grid[r + dr[(d + 1) % 4]][c + dc[(d + 1) % 4]] == 0 && visited[r + dr[(d + 1) % 4]][c + dc[(d + 1) % 4]] == 0)
    { // 3) 우회전(시계 90도) 후 직진
        r = r + dr[(d + 1) % 4];
        c = c + dc[(d + 1) % 4];
        d = (d + 1) % 4;
        q1.push(make_pair(r, c));
        visited[r][c] = 1;
    }

    else
    { // 4) 180도 회전 후 직진
        r = r + dr[(d + 2) % 4];
        c = c + dc[(d + 2) % 4];
        d = (d + 2) % 4;
        q1.push(make_pair(r, c));
        visited[r][c] = 1;
    }
}

// [BFS] (sr, sc)에서 시작해 갈 수 있는 모든 바다까지의 거리를 BFS_arr에 기록
//  - 시작점을 인자로 받아서 "고래 기준"과 "타겟 기준" 두 번 재사용
//  - BFS_arr: 암초 -1 / 미도달 바다 0 / 도달한 칸은 거리 + 1
void BFS(int sr, int sc)
{
    memcpy(BFS_arr, grid, sizeof(BFS_arr)); // 암초 -1, 바다 0으로 초기화 (memset 아님!)
    BFS_arr[sr][sc] = 1;                    // 시작점 = 1 (0이면 미도달 바다와 구분이 안 됨)
    q2.push(make_pair(sr, sc));
    while (!q2.empty())
    {
        pair<int, int> curr_v = q2.front();
        q2.pop();
        int c_r = curr_v.first;
        int c_c = curr_v.second;

        for (int i = 0; i < 4; i++)
        {
            int nr = c_r + dr[i];
            int nc = c_c + dc[i];

            if (canGo(nr, nc)) // 범위 안 + 아직 안 간 바다만
            {
                BFS_arr[nr][nc] = BFS_arr[c_r][c_c] + 1; // 거리 = 현재 칸 + 1
                q2.push(make_pair(nr, nc));
            }
        }
    }
}

// [타겟 찾기] 고래 기준 BFS 결과에서 "도달 가능 + 미방문" 바다 중 가장 가까운 칸
//  - 행 1부터, 열 1부터 순서대로 보면서 "< min"일 때만 갱신
//    → 거리가 같으면 먼저 만난 칸(행 작은 칸 → 열 작은 칸)이 자동으로 남음
//  - 후보가 없으면 (-1, -1) 반환 → main에서 종료
pair<pair<int, int>, int> findMinOfBFS()
{
    int min_r = -1, min_c = -1;
    int min = 1000; // 어차피 100 못 넘음

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // BFS_arr > 0  : 고래가 갈 수 있는 칸 (암초 -1, 미도달 0 제외)
            // visited == 0 : 아직 방문 안 한 바다 (시작점 등 방문한 칸 제외)
            if (BFS_arr[i][j] > 0 && visited[i][j] == 0 && BFS_arr[i][j] < min)
            {
                min_r = i;
                min_c = j;
                min = BFS_arr[i][j];
            }
        }
    }
    pair<int, int> a = make_pair(min_r, min_c);

    return (make_pair(a, min));
}

// [타겟으로 이동] 타겟에서 BFS를 다시 돌려 "각 칸에서 타겟까지 남은 거리"를 구한 뒤
//  좌 > 하 > 우 > 상 순서로, 남은 거리가 정확히 1 줄어드는 칸으로 한 걸음씩 이동
//  - 암초(-1)와 미도달(0)은 "현재 - 1"(항상 1 이상)과 같아질 수 없어서 자동으로 걸러짐
//  - 마지막으로 이동한 방향이 d에 남음 = 도착 후 바라보는 방향
void gotoMinOfBFS(pair<pair<int, int>, int> target)
{
    int tr = target.first.first;
    int tc = target.first.second;

    BFS(tr, tc); // 이제 BFS_arr = 각 칸에서 목표까지 남은 거리 (+1)

    int order[4] = {3, 2, 1, 0}; // 좌, 하, 우, 상 (dr/dc 인덱스)
    while (!(r == tr && c == tc))
    {
        for (int k = 0; k < 4; k++)
        {
            int nd = order[k];
            int nr = r + dr[nd], nc = c + dc[nd];
            if (inRange(nr, nc) && BFS_arr[nr][nc] == BFS_arr[r][c] - 1)
            {
                r = nr;
                c = nc;
                d = nd; // 이동한 방향으로 갱신
                break;  // 우선순위가 가장 높은 칸 하나만
            }
        }
    }
    // 도착한 타겟 칸 방문 처리 + 출력 목록에 추가
    // (가는 길에 지나는 칸은 이미 방문한 바다라서 따로 기록하지 않음)
    q1.push(make_pair(r, c));
    visited[r][c] = 1;
}

// [BFS 이동 조건] 범위 안 + BFS_arr == 0 (아직 안 간 바다)
//  - == 0 하나로 암초(-1)와 이미 간 칸(양수)을 동시에 걸러줌
//  - 주의: = 가 아니라 ==
bool canGo(int nr, int nc)
{
    return (inRange(nr, nc) && BFS_arr[nr][nc] == 0);
}

// [범위 체크] 1-index 기준 1 ~ N
bool inRange(int nr, int nc)
{
    return (nr > 0 && nr <= N && nc > 0 && nc <= N);
}
