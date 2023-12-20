#include <iostream>
#include <vector>

using namespace std;

int ChessboardSize; // 1~14
int NumberOfCases;

vector<bool> CheckColumn;
vector<bool> CheckUpRightDiagonal;
vector<bool> CheckUpLeftDiagonal;

void DFS(int CurrentRow);

int main()
{
    cin >> ChessboardSize;
    CheckColumn          = vector<bool>(ChessboardSize, false);
    int DiagnoalSize     = ChessboardSize * 2 - 1;
    CheckUpRightDiagonal = vector<bool>(DiagnoalSize, false);
    CheckUpLeftDiagonal  = vector<bool>(DiagnoalSize, false);

    DFS(0);

    cout << NumberOfCases << endl;
}

void DFS(int CurrentRow)
{
    if (CurrentRow == ChessboardSize)
    {
        NumberOfCases++;
        return;
    }

    for (int CurrentCol = 0; CurrentCol < ChessboardSize; CurrentCol++)
    {
        if (CheckColumn[CurrentCol] == false &&
            CheckUpRightDiagonal[CurrentRow + CurrentCol] == false &&
            CheckUpLeftDiagonal[CurrentRow - CurrentCol + ChessboardSize - 1] == false)
        {
            CheckColumn[CurrentCol]                                           = true;
            CheckUpRightDiagonal[CurrentRow + CurrentCol]                     = true;
            CheckUpLeftDiagonal[CurrentRow - CurrentCol + ChessboardSize - 1] = true;

            DFS(CurrentRow + 1);

            CheckColumn[CurrentCol]                                           = false;
            CheckUpRightDiagonal[CurrentRow + CurrentCol]                     = false;
            CheckUpLeftDiagonal[CurrentRow - CurrentCol + ChessboardSize - 1] = false;
        }
    }
}