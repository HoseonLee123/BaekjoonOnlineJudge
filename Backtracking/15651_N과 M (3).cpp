#include <iostream>
#include <vector>

using namespace std;

int         LastNumber, TargetCount; // 1 <= TargetCount <= LastNumber <= 7
vector<int> Sequence;

void DFS(int CurrentCount);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> LastNumber >> TargetCount;
    Sequence = vector<int>(TargetCount, 0);
    DFS(0);
}

void DFS(int CurrentCount)
{
    if (CurrentCount == TargetCount)
    {
        for (const auto& Element : Sequence)
        {
            cout << Element << " ";
        }
        cout << '\n';

        return;
    }

    for (int CurrentNumber = 1; CurrentNumber < LastNumber + 1; CurrentNumber++)
    {
        Sequence[CurrentCount] = CurrentNumber;

        DFS(CurrentCount + 1);
    }
}