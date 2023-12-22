#include <iostream>
#include <vector>

using namespace std;

int         LastNumber, TargetCount; // 1 <= TargetCount <= LastNumber <= 8
vector<int> Sequence;

void DFS(int CurrentCount, int StartNumber);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> LastNumber >> TargetCount;
    Sequence = vector<int>(TargetCount, 0);

    DFS(0, 1);
}

void DFS(int CurrentCount, int StartNumber)
{
    if (CurrentCount == TargetCount)
    {
        for (const auto& Element : Sequence)
        {
            cout << Element << " ";
        }
        cout << endl;

        return;
    }

    for (int CurrentNumber = StartNumber; CurrentNumber < LastNumber + 1; CurrentNumber++)
    {
        Sequence[CurrentCount] = CurrentNumber;

        DFS(CurrentCount + 1, CurrentNumber);
    }
}