#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int GameBoardSize; // 4~100
    cin >> GameBoardSize;

    vector<vector<int>> GameBoard(GameBoardSize, vector<int>(GameBoardSize, 0));
    for (auto& OneRow : GameBoard)
    {
        for (auto& Element : OneRow)
        {
            cin >> Element;
        }
    }

    vector<vector<long long>> PathBoard(GameBoardSize, vector<long long>(GameBoardSize, 0));
    PathBoard[0][0] = 1;
    for (int Row = 0; Row < GameBoardSize; Row++)
    {
        for (int Col = 0; Col < GameBoardSize; Col++)
        {
            // If there's a path and can move.
            if (PathBoard[Row][Col] != 0 && GameBoard[Row][Col] != 0)
            {
                int MovingDistance = GameBoard[Row][Col];
                int NextRow        = Row + MovingDistance;
                int NextCol        = Col + MovingDistance;

                if (NextRow < GameBoardSize)
                {
                    PathBoard[NextRow][Col] = PathBoard[NextRow][Col] + PathBoard[Row][Col];
                }
                if (NextCol < GameBoardSize)
                {
                    PathBoard[Row][NextCol] = PathBoard[Row][NextCol] + PathBoard[Row][Col];
                }
            }
        }
    }

    cout << PathBoard[GameBoardSize - 1][GameBoardSize - 1] << endl;
}