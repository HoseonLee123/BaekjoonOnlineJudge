#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::queue;
using std::pair;

void BFS(vector<vector<int>>& Maze, vector<vector<int>>& Path, int TargetRow, int TargetCol)
{
    queue<pair<int, int>> Waiting;
    Waiting.push({TargetRow, TargetCol});
    vector<pair<int, int>> DirectionSet = {
        { 0,  1},
        { 1,  0},
        { 0, -1},
        {-1,  0}
    };

    while (!Waiting.empty())
    {
        int CurrentRow = Waiting.front().first;
        int CurrentCol = Waiting.front().second;
        Waiting.pop();

        for (const pair<int, int>& Dir : DirectionSet)
        {
            int NextRow = CurrentRow + Dir.first;
            int NextCol = CurrentCol + Dir.second;

            if (Maze[NextRow][NextCol] == 1 && Path[NextRow][NextCol] == 0)
            {
                Waiting.push({NextRow, NextCol});
                Path[NextRow][NextCol] = Path[CurrentRow][CurrentCol] + 1;
            }
        }
    }
}

int main()
{
    int MazeRow, MazeCol;
    cin >> MazeRow >> MazeCol; // 2~100

    vector<vector<int>> Maze(MazeRow + 2, vector<int>(MazeCol + 2, 0));
    for (int Row = 1; Row < MazeRow + 1; Row++)
    {
        string OneRow {};
        cin >> OneRow;
        for (int Col = 1, OneRowIndex = 0; Col < MazeCol + 1; Col++, OneRowIndex++)
        {
            Maze[Row][Col] = OneRow[OneRowIndex] - '0';
        }
    }

    vector<vector<int>> Path(MazeRow + 2, vector<int>(MazeCol + 2, 0));
    Path[1][1] = 1;

    BFS(Maze, Path, 1, 1);

    cout << Path[MazeRow][MazeCol] << endl;
}