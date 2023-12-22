#include <iostream>
#include <vector>

using namespace std;

int         LastNumber, TargetCount; // 1 <= TargetCount <= LastNumber <= 8
vector<int> Sequence;

void        DFS(int CurrentNumber, vector<int> Sequence);
vector<int> SelectNumber(vector<int> Sequence, int TargetNumber);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> LastNumber >> TargetCount;

    DFS(1, Sequence);
}

void DFS(int CurrentNumber, vector<int> Sequence)
{
    if (CurrentNumber > LastNumber)
    {
        if (Sequence.size() == TargetCount)
        {
            for (const auto& Element : Sequence)
            {
                cout << Element << " ";
            }
            cout << endl;
        }
        return;
    }

    DFS(CurrentNumber + 1, SelectNumber(Sequence, CurrentNumber));

    DFS(CurrentNumber + 1, Sequence);
}

vector<int> SelectNumber(vector<int> Sequence, int TargetNumber)
{
    Sequence.push_back(TargetNumber);
    return Sequence;
}