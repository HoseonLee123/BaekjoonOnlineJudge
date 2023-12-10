#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int                    MapSize; // 2~100
vector<vector<int>>    Map;
vector<pair<int, int>> DirectionBundle {
    { 1,  0},
    {-1,  0},
    { 0,  1},
    { 0, -1}
};
int BFS(int RainHeight);

int main()
{
    cin >> MapSize;
    Map = vector<vector<int>>(MapSize, vector<int>(MapSize, 0));

    int MaxHeight {0};
    for (auto& OneRow : Map)
    {
        for (auto& Element : OneRow)
        {
            cin >> Element; // 1~100
            MaxHeight = max(MaxHeight, Element);
        }
    }

    int MaxNumberOfSafeArea {1};
    for (int i = 1; i < MaxHeight; i++)
    {
        MaxNumberOfSafeArea = max(MaxNumberOfSafeArea, BFS(i));
    }

    cout << MaxNumberOfSafeArea << endl;
}

int BFS(int RainHeight)
{
    vector<vector<bool>> SafeArea(MapSize, vector<bool>(MapSize, false));
    for (int Row = 0; Row < MapSize; Row++)
    {
        for (int Col = 0; Col < MapSize; Col++)
        {
            if (Map[Row][Col] > RainHeight)
            {
                SafeArea[Row][Col] = true;
            }
        }
    }

    int NumberOfSafeArea {0};
    for (int Row = 0; Row < MapSize; Row++)
    {
        for (int Col = 0; Col < MapSize; Col++)
        {
            if (SafeArea[Row][Col] == true)
            {
                queue<pair<int, int>> Waiting;
                Waiting.push({Row, Col});
                SafeArea[Row][Col] = false;

                while (Waiting.empty() == false)
                {
                    const int CurrentRow = Waiting.front().first;
                    const int CurrentCol = Waiting.front().second;
                    Waiting.pop();

                    for (const auto& Dir : DirectionBundle)
                    {
                        const int NextRow = CurrentRow + Dir.first;
                        const int NextCol = CurrentCol + Dir.second;

                        if ((NextRow >= 0 && NextRow < MapSize) &&
                            (NextCol >= 0 && NextCol < MapSize) &&
                            (SafeArea[NextRow][NextCol] == true))
                        {
                            Waiting.push({NextRow, NextCol});
                            SafeArea[NextRow][NextCol] = false;
                        }
                    }
                }

                NumberOfSafeArea++;
            }
        }
    }

    return NumberOfSafeArea;
}