#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

int                 BoardRow, BoardCol; // 1~20
int                 Answer {1};
vector<bool>        VisitedAlphabet(128, false);
vector<vector<int>> Board;

vector<pair<int, int>> DirectionBundle {
    { 0,  1},
    { 0, -1},
    { 1,  0},
    {-1,  0}
};

int DFS(const int& CurrentRow, const int& CurrentCol, int& MovingCount);

int main()
{
    cin >> BoardRow >> BoardCol;
    Board = vector<vector<int>>(BoardRow, vector<int>(BoardCol, 0));

    for (int Row = 0; Row < BoardRow; Row++)
    {
        string OneRow;
        cin >> OneRow;
        for (int Col = 0; Col < BoardCol; Col++)
        {
            Board[Row][Col] = OneRow[Col];
        }
    }

    int MovingCount              = 1;
    VisitedAlphabet[Board[0][0]] = true;
    cout << DFS(0, 0, MovingCount) << endl;
}

int DFS(const int& CurrentRow, const int& CurrentCol, int& MovingCount)
{
    Answer = max(Answer, MovingCount);

    for (const auto& Dir : DirectionBundle)
    {
        int NextRow = CurrentRow + Dir.first;
        int NextCol = CurrentCol + Dir.second;

        if ((NextRow >= 0 && NextRow < BoardRow) &&
            (NextCol >= 0 && NextCol < BoardCol) &&
            (VisitedAlphabet[Board[NextRow][NextCol]] == false))
        {
            // Backtracking Technique
            VisitedAlphabet[Board[NextRow][NextCol]] = true;
            MovingCount++;
            DFS(NextRow, NextCol, MovingCount);
            VisitedAlphabet[Board[NextRow][NextCol]] = false;
            MovingCount--;
        }
    }

    return Answer;
}