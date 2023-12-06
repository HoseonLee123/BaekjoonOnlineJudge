#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int                  NumberOfComputers; // 1~100
int                  NumberOfConnection;
vector<vector<bool>> Network;
vector<bool>         Infected;
int                  NumberOfInfectedComputers = 0;
int                  DFS(const int& Current);
int                  BFS(queue<int>& Waiting);

int main()
{
    cin >> NumberOfComputers >> NumberOfConnection;

    // Computer number starts from 1.
    Network  = vector<vector<bool>>(NumberOfComputers + 1, vector<bool>(NumberOfComputers + 1, false));
    Infected = vector<bool>(NumberOfComputers + 1, false);

    for (int i = 0; i < NumberOfConnection; i++)
    {
        int Connection1, Connection2;
        cin >> Connection1 >> Connection2;

        Network[Connection1][Connection2] = true;
        Network[Connection2][Connection1] = true;
    }

    int FirstInfectedComputerNumber       = 1;
    Infected[FirstInfectedComputerNumber] = true;

    // DFS
    cout << DFS(FirstInfectedComputerNumber) << endl;

    // BFS
    queue<int> Waiting;
    Waiting.push(FirstInfectedComputerNumber);
    // cout << BFS(Waiting) << endl;
}

int DFS(const int& CurrentInfectedComputerNumber)
{
    for (int NextTarget = 1; NextTarget < NumberOfComputers + 1; NextTarget++)
    {
        if (Network[CurrentInfectedComputerNumber][NextTarget] == false)
            continue;

        if (Infected[NextTarget] == true)
            continue;

        Infected[NextTarget] = true;
        NumberOfInfectedComputers++;
        cout << "Infected: " << NextTarget << endl;
        DFS(NextTarget);
    }

    return NumberOfInfectedComputers;
}

int BFS(queue<int>& Waiting)
{
    while (Waiting.empty() == false)
    {
        int CurrentInfectedComputerNumber = Waiting.front();
        Waiting.pop();

        for (int NextTarget = 1; NextTarget < NumberOfComputers + 1; NextTarget++)
        {
            if (Network[CurrentInfectedComputerNumber][NextTarget] == false)
                continue;

            if (Infected[NextTarget] == true)
                continue;

            Infected[NextTarget] = true;
            NumberOfInfectedComputers++;
            cout << "Infected: " << NextTarget << endl;
            Waiting.push(NextTarget);
        }
    }

    return NumberOfInfectedComputers;
}