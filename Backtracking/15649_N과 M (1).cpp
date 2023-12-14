#include <iostream>
#include <vector>

using namespace std;

int          LastNumber, TargetCount; // 1 <= TargetCount <= LastNumber <= 8
vector<bool> Visited;
vector<int>  Answer;
void         DFS(int CurrentCount);

int main()
{
    cin >> LastNumber >> TargetCount;
    Visited = vector<bool>(LastNumber + 1, false);
    Answer  = vector<int>(TargetCount, 0);

    DFS(0);
}

void DFS(int CurrentCount)
{
    if (CurrentCount == TargetCount)
    {
        for (const auto& Element : Answer)
        {
            cout << Element << " ";
        }
        cout << '\n'; // cout << endl; occurs time out.
        return;
    }

    for (int i = 1; i < LastNumber + 1; i++)
    {
        if (Visited[i] == false)
        {
            Answer[CurrentCount] = i;
            Visited[i]           = true;

            DFS(CurrentCount + 1);

            Visited[i] = false;
        }
    }
}