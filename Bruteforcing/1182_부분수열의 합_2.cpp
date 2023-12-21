#include <iostream>
#include <vector>

using namespace std;

int         NumberOfElements; // 1~20
int         TargetSum;        // -1,000,000~1,000,000
vector<int> Sequence;         // -100,000~100,000
int         NumberOfCases = 0;

void DFS(int CurrentIndex, int Sum, int Count);

int main()
{
    cin >> NumberOfElements >> TargetSum;
    for (int i = 0; i < NumberOfElements; i++)
    {
        int Temp;
        cin >> Temp;
        Sequence.push_back(Temp);
    }

    DFS(0, 0, 0);

    cout << NumberOfCases << endl;
}

void DFS(int CurrentIndex, int Sum, int Count)
{
    if (CurrentIndex == NumberOfElements)
    {
        if (Sum == TargetSum && Count > 0)
        {
            NumberOfCases++;
        }

        return;
    }

    DFS(CurrentIndex + 1, Sum + Sequence[CurrentIndex], Count + 1);

    DFS(CurrentIndex + 1, Sum, Count);
}