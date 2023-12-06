#include <iostream>
#include <queue>

using namespace std;

int BFS(const int& Start, const int& End);

int main()
{
    int Position1, Position2; // 0~100000
    cin >> Position1 >> Position2;

    cout << BFS(Position1, Position2) << endl;
}

int BFS(const int& Start, const int& End)
{
    // return 1
    /*if (Start == End)
        return 0;*/

    vector<int> VisitingTime(200001, -1);

    queue<int> Waiting;
    Waiting.push(Start);
    VisitingTime[Start] = 0;

    while (Waiting.empty() == false)
    {
        int CurrentPosition = Waiting.front();
        Waiting.pop();

        // return 2
        if (CurrentPosition == End)
        {
            return VisitingTime[CurrentPosition];
        }

        for (const int& NextPosition : {CurrentPosition - 1, CurrentPosition + 1, CurrentPosition * 2})
        {
            if ((NextPosition >= 0 && NextPosition <= 200000) && VisitingTime[NextPosition] == -1)
            {
                // return 1
                /*if (NextPosition == End)
                {
                    return VisitingTime[CurrentPosition] + 1;
                }*/

                VisitingTime[NextPosition] = VisitingTime[CurrentPosition] + 1;
                Waiting.push(NextPosition);
            }
        }
    }
}
