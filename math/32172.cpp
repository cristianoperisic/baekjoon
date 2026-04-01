#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main(void){
    int n;
    cin >> n;
    vector<int> A(n+1, -1); // 0부터 n까지 n+1개가 필요함
    set<int> B;           // 겹치는지 체크할 집합

    A[0] = 0;
    B.insert(A[0]);       // 맨 처음꺼 넣어주고 

    for (int i = 1; i <= n;i++){
        int k = A[i - 1] - i;
        if(k>0 && B.find(k) == B.end())  // A[i]가 0보다 크면서 이전에 겹치는게 있으면 안됨
            A[i] = k;
        else
            A[i] = k + 2*i;             // 겹치거나 0보다 작을 경우 A[i] = A[i-1]+i니까 k+2i 해준다

        B.insert(A[i]);
    }

    cout << A[n];

    return 0;
}