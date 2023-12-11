#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define SEA 0

int                    MapRow, MapCol; // 3~300
vector<vector<int>>    Map;
vector<vector<bool>>   IsThereCurrentlyIceberg;
vector<pair<int, int>> DirectionBundle {
    { 1,  0},
    {-1,  0},
    { 0,  1},
    { 0, -1}
};

void Melting();
int  CheckSeparateIcebergBFS();

int main()
{
    cin >> MapRow >> MapCol;
    Map                     = vector<vector<int>>(MapRow, vector<int>(MapCol, SEA));
    IsThereCurrentlyIceberg = vector<vector<bool>>(MapRow, vector<bool>(MapCol, false));

    for (int Row = 0; Row < MapRow; Row++)
    {
        for (int Col = 0; Col < MapCol; Col++)
        {
            // 0 == sea
            // 1~10 == iceberg
            cin >> Map[Row][Col];

            if (Map[Row][Col] != SEA)
            {
                IsThereCurrentlyIceberg[Row][Col] = true;
            }
        }
    }

    for (int Year = 1;; Year++)
    {
        Melting();

        int NumberOfeparateIceberg = CheckSeparateIcebergBFS();

        if (NumberOfeparateIceberg == 1)
        {
            cout << Year << endl;
            break;
        }
        else if (NumberOfeparateIceberg == -1)
        {
            cout << 0 << endl;
            break;
        }
    }

    return 0;
}

void Melting()
{
    vector<pair<int, int>> NextYearIcebergToSea;

    for (int Row = 1; Row < MapRow - 1; Row++)
    {
        for (int Col = 1; Col < MapCol - 1; Col++)
        {
            if (Map[Row][Col] != SEA)
            {
                for (const auto& Dir : DirectionBundle)
                {
                    int NextRow = Row + Dir.first;
                    int NextCol = Col + Dir.second;

                    if (IsThereCurrentlyIceberg[NextRow][NextCol] == true)
                        continue;

                    if (Map[NextRow][NextCol] == SEA)
                    {
                        Map[Row][Col] -= 1;
                    }
                }

                if (Map[Row][Col] < SEA)
                {
                    Map[Row][Col] = 0;
                }

                if (Map[Row][Col] == SEA)
                {
                    NextYearIcebergToSea.push_back({Row, Col});
                }
            }
        }
    }

    for (const auto& Change : NextYearIcebergToSea)
    {
        IsThereCurrentlyIceberg[Change.first][Change.second] = false;
    }
}

int CheckSeparateIcebergBFS()
{
    int NumberOfSeparateIceberg {-1};

    vector<vector<bool>> Visited(MapRow, vector<bool>(MapCol, false));
    for (int Row = 1; Row < MapRow - 1; Row++)
    {
        for (int Col = 1; Col < MapCol - 1; Col++)
        {
            if (Map[Row][Col] != SEA && Visited[Row][Col] == false)
            {
                queue<pair<int, int>> Waiting;
                Waiting.push({Row, Col});
                Visited[Row][Col] = true;

                while (Waiting.empty() == false)
                {
                    int CurrentRow = Waiting.front().first;
                    int CurrentCol = Waiting.front().second;
                    Waiting.pop();

                    for (const auto& Dir : DirectionBundle)
                    {
                        int NextRow = CurrentRow + Dir.first;
                        int NextCol = CurrentCol + Dir.second;

                        if (Map[NextRow][NextCol] != SEA && Visited[NextRow][NextCol] == false)
                        {
                            Waiting.push({NextRow, NextCol});
                            Visited[NextRow][NextCol] = true;
                        }
                    }
                }

                NumberOfSeparateIceberg++;
            }

            if (NumberOfSeparateIceberg == 1)
            {
                return NumberOfSeparateIceberg;
            }
        }
    }

    return NumberOfSeparateIceberg;
}
