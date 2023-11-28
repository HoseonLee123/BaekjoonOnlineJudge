#include <iostream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::pair;

int DFS(vector<vector<int>>& Map, vector<vector<int>>& Path, int CurrentRow, int CurrentCol)
{
    // Memorization
    if (Path[CurrentRow][CurrentCol] == -1)
    {
        Path[CurrentRow][CurrentCol] = 0;

        vector<pair<int, int>> DirectionSet = {
            { 0,  1},
            { 1,  0},
            { 0, -1},
            {-1,  0}
        };
        for (const pair<int, int>& Dir : DirectionSet)
        {
            int PrevRow = CurrentRow + Dir.first;
            int PrevCol = CurrentCol + Dir.second;
            if (Map[PrevRow][PrevCol] > Map[CurrentRow][CurrentCol])
            {
                Path[CurrentRow][CurrentCol] += DFS(Map, Path, PrevRow, PrevCol);
            }
        }
    }

    return Path[CurrentRow][CurrentCol];
}

int main()
{
    int MapRow, MapCol; // 1~500
    cin >> MapRow >> MapCol;

    vector<vector<int>> Map(MapRow + 2, vector<int>(MapCol + 2, 0));
    for (int Row = 1; Row < MapRow + 1; Row++)
    {
        for (int Col = 1; Col < MapCol + 1; Col++)
        {
            int Temp;
            cin >> Temp; // 1~10000
            Map[Row][Col] = Temp;
        }
    }

    vector<vector<int>> Path(MapRow + 2, vector<int>(MapCol + 2, -1));
    Path[1][1] = 1;

    cout << DFS(Map, Path, MapRow, MapCol) << endl;
}
