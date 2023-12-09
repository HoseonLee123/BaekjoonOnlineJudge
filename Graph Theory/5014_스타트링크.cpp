#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int TotalFloor, GanghoFloor, TargetFloor; // 1~1000000
int MovingUp, MovingDown;                 // 0~1000000
int BFS();

int main()
{
    cin >> TotalFloor >> GanghoFloor >> TargetFloor >> MovingUp >> MovingDown;

    int Answer = BFS();
    if (Answer == -1)
    {
        cout << "use the stairs" << endl;
    }
    else
    {
        cout << Answer << endl;
    }
}

int BFS()
{
    // Initial value setting
    queue<pair<int, int>> Waiting;
    vector<bool>          VisitedFloor(TotalFloor + 1, false);
    Waiting.push({GanghoFloor, 0});
    VisitedFloor[GanghoFloor] = true;

    while (Waiting.empty() == false)
    {
        int CurrentFloor              = Waiting.front().first;
        int CurrentButtonPressedCount = Waiting.front().second;
        Waiting.pop();

        if (CurrentFloor == TargetFloor)
        {
            return CurrentButtonPressedCount;
        }

        for (const auto& Dir : {MovingUp, -MovingDown})
        {
            int NextFloor              = CurrentFloor + Dir;
            int NextButtonPressedCount = CurrentButtonPressedCount + 1;

            if ((NextFloor >= 1 && NextFloor < TotalFloor + 1) && VisitedFloor[NextFloor] == false)
            {
                Waiting.push({NextFloor, NextButtonPressedCount});
                VisitedFloor[NextFloor] = true;
            }
        }
    }

    // use the stairs
    return -1;
}