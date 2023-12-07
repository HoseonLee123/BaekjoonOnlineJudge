#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int                    MapSize; // 5~25
vector<vector<bool>>   Map;
vector<vector<int>>    Numbering;
vector<pair<int, int>> DirectionBundle {
    { 1,  0},
    {-1,  0},
    { 0,  1},
    { 0, -1}
};
int DFS(const int& CurrentRow, const int& CurrentCol, const int& Marking, int& NumberOfMarking);
int BFS(const int& StartRow, const int& StartCol, const int& Marking, int& NumberOfMarking);

int main()
{
    cin >> MapSize;

    Map       = vector<vector<bool>>(MapSize, vector<bool>());
    Numbering = vector<vector<int>>(MapSize, vector<int>(MapSize, 0));

    for (auto& OneRow : Map)
    {
        string Temp;
        cin >> Temp;
        vector<bool> ColumnElements;
        for (const auto& StringTempElement : Temp)
        {
            ColumnElements.push_back(StringTempElement - '0');
        }
        OneRow = ColumnElements;
    }

    int         Marking = 1;
    vector<int> NumberOfEachComplex;
    for (int Row = 0; Row < MapSize; Row++)
    {
        for (int Col = 0; Col < MapSize; Col++)
        {
            if (Map[Row][Col] == true && Numbering[Row][Col] == 0)
            {
                int NumberOfMarking {0};

                // NumberOfEachComplex.push_back(DFS(Row, Col, Marking, NumberOfMarking));
                NumberOfEachComplex.push_back(BFS(Row, Col, Marking, NumberOfMarking));

                Marking++;
            }
        }
    }

    sort(NumberOfEachComplex.begin(), NumberOfEachComplex.end());
    cout << NumberOfEachComplex.size() << endl;
    for (const auto& Element : NumberOfEachComplex)
    {
        cout << Element << endl;
    }
}

int DFS(const int& CurrentRow, const int& CurrentCol, const int& Marking, int& NumberOfMarking)
{
    Numbering[CurrentRow][CurrentCol] = Marking;
    NumberOfMarking++;

    for (const auto& Dir : DirectionBundle)
    {
        int NextRow = CurrentRow + Dir.first;
        int NextCol = CurrentCol + Dir.second;

        // First condition: if the next is within a range.
        // Second condition: if the next is a house.
        // Third condition: if the next has not been numbered yet.
        if ((NextRow >= 0 && NextRow < MapSize) &&
            (NextCol >= 0 && NextCol < MapSize) &&
            Map[NextRow][NextCol] == true &&
            Numbering[NextRow][NextCol] == 0)
        {
            DFS(NextRow, NextCol, Marking, NumberOfMarking);
        }
    }

    return NumberOfMarking;
}

int BFS(const int& StartRow, const int& StartCol, const int& Marking, int& NumberOfMarking)
{
    queue<pair<int, int>> Waiting;
    Waiting.push({StartRow, StartCol});
    Numbering[StartRow][StartCol] = Marking;
    NumberOfMarking++;

    while (Waiting.empty() == false)
    {
        int CurrentRow = Waiting.front().first;
        int CurrentCol = Waiting.front().second;
        Waiting.pop();

        for (const auto& Dir : DirectionBundle)
        {
            int NextRow = CurrentRow + Dir.first;
            int NextCol = CurrentCol + Dir.second;

            // First condition: if the next is within a range.
            // Second condition: if the next is a house.
            // Third condition: if the next has not been numbered yet.
            if ((NextRow >= 0 && NextRow < MapSize) &&
                (NextCol >= 0 && NextCol < MapSize) &&
                Map[NextRow][NextCol] == true &&
                Numbering[NextRow][NextCol] == 0)
            {
                Numbering[NextRow][NextCol] = Marking;
                NumberOfMarking++;

                Waiting.push({NextRow, NextCol});
            }
        }
    }

    return NumberOfMarking;
}