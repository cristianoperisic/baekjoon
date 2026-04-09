#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> S;
void dfs(int node, int N_C, const vector<vector<int>>& graph);

int main(void){
    int N_C, N_R; // 컴퓨터 수, road 스
    cin >> N_C >> N_R;

    vector<vector<int>> graph(N_C + 1, vector<int>(N_C + 1, 0));

    for (int i = 0; i < N_R;i++){
        int u,v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    dfs(1, N_C, graph);
    cout << S.size()-1;
    return 0;
}

void dfs(int node, int N_C, const vector<vector<int>>& graph){
    S.insert(node);

    for (int next = 1; next <= N_C; ++next){
        if(!S.count(next) && graph[node][next])
            dfs(next, N_C, graph);
    }
}


