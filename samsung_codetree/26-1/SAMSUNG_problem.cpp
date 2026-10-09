// =====================================================================
// 코드트리 삼성 기출 | 2026 상반기 오전 1번 · 아기 바다거북의 대모험: 해저 화산 지대
// ---------------------------------------------------------------------
// [한 턴의 흐름]  (최대 100턴)
//   1단계 거북이 이동 : 번호 순서대로, 살아 있고 도착 안 한 거북이만
//                      안식처 (N, N)에서 BFS → R D L U 순으로 "거리 1 작은 칸"으로 한 칸
//                      (N, N) 도착 시 도착 시간 기록, 지도에서 제외
//   2단계 압력 증가   : 모든 화산 압력 +10
//   3단계 분출        : ① 압력 >= P 인 화산 분출
//                      ② 연쇄: 아직 안 터진 화산 중 (압력 + 받은 열기) >= P 이면 분출
//                         → 새로 터지는 화산이 없을 때까지 반복
//                      ③ 열기 >= 20 인 칸의 거북이는 화석
//   4단계 초기화      : 열기 전부 0, 분출한 화산만 압력 0
//
// [이 문제에서 배운 것]
//   1. "최단 경로 + 방향 우선순위" → 목표(안식처)에서 역방향 BFS (아기 고래와 같은 패턴)
//   2. BFS 배열 하나로 -1(장애물) / 0(미방문) / 양수(거리+1, 시작점=1) 표현
//   3. 십자 모양 열기: "방향이 바깥 반복, 거리가 안쪽 반복" → 방향별로 따로 멈출 수 있음
//   4. 연쇄 반응 = "변화 없을 때까지 반복" 플래그 + 이미 처리한 대상은 건너뛰기
//   5. 결과 기본값을 실패(-1)로 두고, 성공(도착)했을 때만 덮어쓰기
//   6. 함수 하나씩 짜고 작은 입력 + printMap으로 바로 확인하면서 진행
// =====================================================================

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

// ----- 함수 선언 -----
void MakeCanGoMap();
pair<int, int> doBFS_Move(int r, int c);
bool inRange(int nr, int nc);
void printMap(int arr[22][22]);
void oneExplode(int r, int c, int capacity);
void eruptAll();
void pressureUp();

// 방향 배열: 문제의 우선순위 순서 그대로 (0:R 1:D 2:L 3:U)
//  → BFS 후 이 순서대로 보면 자동으로 R > D > L > U 우선순위가 지켜짐
int dr[4] = {0, 1, 0, -1}; // R D L U
int dc[4] = {1, 0, -1, 0};

int N, M, K;                  // N: 격자 크기, M: 바다거북 수, K: 해저 화산 수
int grid[22][22];             // 지도 (1-index)  0: 바다 / 1: 산호초
int BFS[22][22];              // 안식처 기준 거리 맵  -1: 장애물 / 0: 미방문 / 양수: 거리 + 1
int heat[22][22];             // 이번 턴에 각 칸이 받은 열기 합계 (여러 화산 열기는 누적)
int volcano_pressure[22][22]; // 화산 칸의 현재 압력
int tmp[22][22];              // 임시 저장용 배열 (최종 코드에서는 사용 안 함)

// 바다거북 상태
//  이동 중 : alive = true,  arrived = false  → 이동 O, 화석 판정 O, BFS 장애물 O
//  화석    : alive = false, arrived = false  → 이동 X, 화석 판정 X, BFS 장애물 O
//  도착    : alive = false, arrived = true   → 이동 X, 화석 판정 X, BFS 장애물 X (지도에서 제외)
struct Turtle
{
    int r, c;
    bool alive, arrived; // alive = "아직 판 위에서 움직이는 중", arrived = 안식처 도착
    int time;            // 도착 시간 (기본값 -1 → 도착했을 때만 덮어씀)
};

// 해저 화산
//  pressure 칸에는 입력받은 "임계치 P"가 들어 있음 (실제 압력은 volcano_pressure 배열)
struct Volcano
{
    int r, c, pressure;
    bool erupted; // 이번 턴에 분출했는지 (연쇄 반응 중복 방지)
};

vector<Turtle> m;  // 바다거북 목록 (번호 순서 = 이동 순서)
vector<Volcano> k; // 해저 화산 목록
queue<pair<int, int>> BFS_q;

int main()
{
    cin >> N >> M >> K;

    // 지도 입력 (1-index)
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> grid[i][j];
        }
    }

    // 거북이 입력: 0-index로 주어지므로 +1 해서 1-index로 변환
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a++;
        b++; // 0 index 싫습니다

        m.push_back({a, b, 1, 0, -1}); // 살아 있음, 미도착, 도착 시간 기본값 -1 (못 가면 그대로 -1 출력)
    }

    // 화산 입력: 위치(0-index → 1-index), 임계치 P
    for (int i = 0; i < K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a++;
        b++; // 0 index 싫습니다
        Volcano v = {
            a,
            b,
            c, // 임계치 P
            false};
        k.push_back(v);
    }

    int turn = 1;
    while (turn <= 100) //  최대 100턴 동안
    {
        // ----- 1단계: 바다거북 이동 (번호 순서대로 한 마리씩) -----
        for (int i = 0; i < m.size(); i++)
        { // 모든 거북이에 대해
            if (m[i].alive && !m[i].arrived)
            { // 살아있고 아직 도착 안 했다면
                pair<int, int> locate = doBFS_Move(m[i].r, m[i].c);
                m[i].r = locate.first;
                m[i].c = locate.second;

                if (m[i].r == N && m[i].c == N) // 안식처 도착
                {
                    m[i].time = turn;     // 도착 시간 기록
                    m[i].arrived = true;  // 지도에서 제외 (BFS 장애물 X)
                    m[i].alive = false;   // 이후 이동/화석 판정 대상에서 제외
                }
            }
        }

        // ----- 2단계: 압력 증가 -----
        pressureUp();

        // ----- 3단계 + 4단계: 분출, 연쇄, 화석 판정, 초기화 -----
        eruptAll();

        turn++;
    }

    // 도착 시간 출력 (도착 못 했거나 화석이면 -1)
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i].time << '\n';
    }
    return 0;
}

// [1단계] 거북이 (r, c)를 최단 경로로 한 칸 이동시킨 좌표를 반환
//  - 안식처 (N, N)에서 BFS를 돌려 "각 칸에서 안식처까지 거리"를 구함
//    (거북이에서 BFS를 돌리면 어느 방향이 최단인지 알 수 없음 → 역방향 BFS)
//  - R D L U 순서로 "거리가 정확히 1 작은 칸"을 찾으면 그쪽으로 이동
//  - 경로가 없으면(거북이 칸이 끝까지 0) 제자리
pair<int, int> doBFS_Move(int r, int c) // BFS map을 제작 후 한칸 이동 한 다음에 좌표 제공, 도착지가 고정이라 좋다
{                                       // r,c는 현재 찾는 거북이의 좌표
    MakeCanGoMap();     // 장애물(-1) 표시
    BFS_q.push({N, N}); // NXN에서 BFS 시작
    BFS[N][N] = 1;      // 시작점 = 1 (0은 "미방문"이라 겹치지 않게)
    BFS[r][c] = 0;      // 본인쪽은 갈 수 있어야하니까 (자기 칸은 장애물에서 제외)

    while (!BFS_q.empty())
    {
        pair<int, int> curr_v = BFS_q.front();
        BFS_q.pop();
        int c_r = curr_v.first;
        int c_c = curr_v.second;

        for (int i = 0; i < 4; i++)
        {
            int nr = c_r + dr[i];
            int nc = c_c + dc[i];

            // == 0 하나로 장애물(-1)과 이미 간 칸(양수)을 동시에 걸러줌
            if (inRange(nr, nc) && BFS[nr][nc] == 0)
            {
                BFS_q.push({nr, nc});
                BFS[nr][nc] = BFS[c_r][c_c] + 1;
            }
        }
    }

    if (BFS[r][c] != 0) // 최단 경로 존재 (거북이 칸까지 BFS가 도달함)
    {
        for (int i = 0; i < 4; i++) // R D L U 우선순위
        {
            int c_r = r + dr[i];
            int c_c = c + dc[i];
            // 안식처까지 거리가 1 줄어드는 칸 = 최단 경로 위의 다음 칸
            if (inRange(c_r, c_c) && BFS[c_r][c_c] == BFS[r][c] - 1)
            {
                r += dr[i];
                c += dc[i];

                return {r, c};
            }
        }
    }

    return {r, c}; // 이동 불가 → 제자리
}

// [범위 체크] 1-index 기준 1 ~ N
bool inRange(int nr, int nc)
{
    return (nr >= 1 && nr <= N && nc >= 1 && nc <= N);
}

// [BFS 장애물 맵 만들기]  -1: 못 감 / 0: 갈 수 있음
//  - 도착 안 한 거북이(이동 중 + 화석)와 산호초를 막음
//  - 도착한 거북이는 지도에서 제외되므로 막지 않음
//  - 화산 칸은 거북이가 지나갈 수 있으므로 막지 않음
void MakeCanGoMap() // BFS에다가 갈 수 있는지 없는지를 반영시키는 맵 -1이면 못가고 0이면 갈 수 있다
{
    memset(BFS, 0, sizeof(BFS));       // BFS 맵 초기화 (sizeof(memset) 아님!)
    for (int i = 0; i < m.size(); i++) // 거북이, 화석이 있다면
    {
        if (!m[i].arrived)
            BFS[m[i].r][m[i].c] = -1;
    }

    for (int i = 1; i <= N; i++) //  산호초가 있다면 (1-index라 1 ~ N)
    {
        for (int j = 1; j <= N; j++)
        {
            if (grid[i][j] == 1)
                BFS[i][j] = -1; // == 아니고 =
        }
    }
}

// [2단계] 모든 화산 압력 +10
void pressureUp() // 압력 증가
{
    for (int i = 0; i < k.size(); i++)
    {
        int a = k[i].r;
        int b = k[i].c;

        volcano_pressure[a][b] += 10;
    }
}

// [화산 하나 분출] (r, c)에서 capacity 열기를 십자 모양으로 퍼뜨림
//  - 중심 칸은 capacity 그대로 (한 번만 더함)
//  - 네 방향 각각 직선으로 한 칸씩: 열기 절반(내림)
//  - 범위 밖 / 산호초 / 열기 0 이면 "그 방향만" 멈춤
//  - 방향이 바깥 반복, 거리가 안쪽 반복이라 방향별로 따로 멈출 수 있음
void oneExplode(int r, int c, int capacity) // 화산 r,c 좌표, 용량 capacity 화산폭발
{
    heat[r][c] += capacity;

    for (int d = 0; d < 4; d++)
    {
        int nr = r;
        int nc = c;
        int h = capacity;
        while (true)
        {
            nr += dr[d];
            nc += dc[d];
            h /= 2; // 한 칸마다 절반 (정수 나눗셈 = 내림)

            if (!inRange(nr, nc) || grid[nr][nc] == 1 || h == 0)
                break;
            heat[nr][nc] += h; // [nr][nc] 순서 주의 (행, 열)
        }
    }
}

// [3단계 + 4단계] 분출 → 연쇄 → 화석 판정 → 초기화
void eruptAll() // 분출 과정, 초기화를 하나의 함수로,
{
    // ① 1차 분출: 압력만으로 P 이상인 화산
    for (int i = 0; i < k.size(); i++)
    {
        if (volcano_pressure[k[i].r][k[i].c] >= k[i].pressure)
        {
            k[i].erupted = true;
            oneExplode(k[i].r, k[i].c, k[i].pressure);
        }
    }

    // ② 연쇄: 압력 + 열기가 P 이상인 "아직 안 터진" 화산
    //    (실제 압력이 오르는 건 아님 → volcano_pressure는 건드리지 않음)
    //    새로 터진 화산의 열기가 또 다른 화산을 터뜨릴 수 있으므로
    //    "새로 터진 게 없을 때까지" 반복 (2차원 폭발 게임과 같은 플래그 패턴)
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 0; i < k.size(); i++)
        {
            if (k[i].erupted)
                continue; // 이미 터진 건 건너뜀 (무한 루프 방지)
            if (volcano_pressure[k[i].r][k[i].c] + heat[k[i].r][k[i].c] >= k[i].pressure)
            {
                k[i].erupted = true;
                oneExplode(k[i].r, k[i].c, k[i].pressure);
                changed = true; // 새로 터졌으니 한 바퀴 더 확인
            }
        }
    }

    // ③ 화석 판정: 이동 중인 거북이 칸의 열기 합이 20 이상이면 화석
    //    (도착한 거북이는 alive = false 라서 자동으로 제외됨)
    for (int i = 0; i < m.size(); i++) // 화석화 체크
    {
        if (m[i].alive == 1 && heat[m[i].r][m[i].c] >= 20)
        {
            m[i].alive = 0;  // 화석: 이후 이동 X, 하지만 BFS 장애물로는 계속 남음
            m[i].time = -1;
        }
    }

    // ④ 초기화: 분출한 화산만 압력 0, 분출 표시 해제 / 열기는 전부 지움
    for (int i = 0; i < k.size(); i++) // 초기화
    {
        if (k[i].erupted == true)
        {
            volcano_pressure[k[i].r][k[i].c] = 0;
            k[i].erupted = false;
        }
    }
    memset(heat, 0, sizeof(heat));
}

// [디버깅용] 2차원 배열 출력 (제출 시 호출하는 줄만 지우면 됨)
void printMap(int arr[22][22])
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << arr[i][j] << '\t';
        cout << '\n';
    }
    cout << "-----\n";
}
