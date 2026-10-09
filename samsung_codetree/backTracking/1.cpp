#include <iostream>
#include <vector>

using namespace std;
void PrintAnswer();
void Choose(int curr_num);

vector<int> answer;

int K, N;

int main()
{
    cin >> K >> N;

    Choose(1);

    return 0;
}

void PrintAnswer()
{
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    cout << "\n";
}

void Choose(int curr_num) // curr_num 위치에 채울 수 고르기
{
    if (curr_num == N + 1)
    {
        PrintAnswer();
        return;
    }

    for (int i = 1; i <= K; i++)
    {
        answer.push_back(i);
        Choose(curr_num + 1);
        answer.pop_back();
    }
}
