#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int Row, Col; // 8~50
    cin >> Row >> Col;

    vector<vector<string>> Chessboard(Row, vector<string>(Col, ""));
    for (int i = 0; i < Row; i++)
    {
        string OneRow {};
        cin >> OneRow;
        for (int j = 0; j < Col; j++)
        {
            Chessboard[i][j] = OneRow[j];
        }
    }

    vector<vector<string>> StandardWhiteChessboard(8, vector<string>(8, ""));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    StandardWhiteChessboard[i][j] = "W";
                }
                else
                {
                    StandardWhiteChessboard[i][j] = "B";
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    StandardWhiteChessboard[i][j] = "B";
                }
                else
                {
                    StandardWhiteChessboard[i][j] = "W";
                }
            }
        }
    }

    vector<vector<string>> StandardBlackChessboard(8, vector<string>(8, ""));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    StandardBlackChessboard[i][j] = "B";
                }
                else
                {
                    StandardBlackChessboard[i][j] = "W";
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    StandardBlackChessboard[i][j] = "W";
                }
                else
                {
                    StandardBlackChessboard[i][j] = "B";
                }
            }
        }
    }

    vector<int> RepaintSet;
    for (int StartRow = 0; StartRow < Row - 7; StartRow++)
    {
        for (int StartCol = 0; StartCol < Col - 7; StartCol++)
        {
            int CompareWithStandardWhiteChessboard {0};
            for (int RepRow = StartRow, StandardRow = 0; RepRow < StartRow + 8; RepRow++, StandardRow++)
            {
                for (int RepCol = StartCol, StandardCol = 0; RepCol < StartCol + 8; RepCol++, StandardCol++)
                {
                    if (Chessboard[RepRow][RepCol] != StandardWhiteChessboard[StandardRow][StandardCol])
                    {
                        CompareWithStandardWhiteChessboard++;
                    }
                }
            }

            int CompareWithStandardBlackChessboard {0};
            for (int RepRow = StartRow, StandardRow = 0; RepRow < StartRow + 8; RepRow++, StandardRow++)
            {
                for (int RepCol = StartCol, StandardCol = 0; RepCol < StartCol + 8; RepCol++, StandardCol++)
                {
                    if (Chessboard[RepRow][RepCol] != StandardBlackChessboard[StandardRow][StandardCol])
                    {
                        CompareWithStandardBlackChessboard++;
                    }
                }
            }

            RepaintSet.push_back(min(CompareWithStandardWhiteChessboard, CompareWithStandardBlackChessboard));
        }
    }

    sort(RepaintSet.begin(), RepaintSet.end());
    cout << RepaintSet[0] << endl;
}