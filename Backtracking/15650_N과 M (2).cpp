#include <iostream>
#include <vector>

using namespace std;

int          LastNumber, TargetCount; // 1 <= TargetCount <= LastNumber <= 8
vector<bool> Selected;
vector<int>  Sequence;

void DFS(int CurrentCount);

int main()
{
    cin >> LastNumber >> TargetCount;
    Selected = vector<bool>(LastNumber + 1, false);
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

    for (int Num = 1; Num <= LastNumber; Num++)
    {
        if (Selected[Num] == false)
        {
            if ((CurrentCount >= 1) && (Sequence[CurrentCount - 1] > Num))
            {
                continue;
            }

            Selected[Num]          = true;
            Sequence[CurrentCount] = Num;

            DFS(CurrentCount + 1);

            Selected[Num] = false;
        }
    }
}