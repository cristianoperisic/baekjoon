#include <iostream>
#include <vector>       // 14888

using namespace std;

int MAX = -1000000000;  // 문제에서 최소가 -10억이라고 함
int MIN = 1000000000; // 문제에서 최대가 10억이라고 함
int N;
void DFS(int plus, int minus, int mutiple, int divide, int x, int sum, vector<int>A);

int main(void){
    cin >> N;
    vector<int> A(N); // N개 숫자 받기
    vector<int> B(4); // +-*/는 각각 몇개인지  

    for (int i = 0; i < N;i++){
        cin >> A[i];
    }

    for (int i = 0; i < 4;i++){
        cin >> B[i];
    }
    DFS(B[0], B[1], B[2], B[3], 0, A[0], A);

    cout << MAX << "\n" << MIN;
    return 0;
}

void DFS(int plus, int minus, int multiple, int divide, int x, int sum, vector<int> A){
    // plus, minus, multiple, divide는 각각 남은 개수
    // x는 연산이 몇번 진행되는지. N-1까지 진행되어야 함
    // sum은 최대 최소를 얻기 위한 비교
    if(x == N-1){
        if (sum > MAX)
            MAX = sum;
        if (sum < MIN)
            MIN = sum;
    }

    if(plus>0){
        DFS(plus - 1, minus, multiple, divide, x + 1, sum + A[x + 1], A);
    }
    if(minus>0){
        DFS(plus , minus-1, multiple, divide, x + 1, sum - A[x + 1], A);
    }
    if(multiple>0){
        DFS(plus , minus, multiple-1, divide, x + 1, sum * A[x + 1], A);
    }
    if(divide>0){
        DFS(plus , minus, multiple, divide-1, x + 1, sum / A[x + 1], A);
    }
}