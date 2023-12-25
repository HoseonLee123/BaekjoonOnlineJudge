#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    constexpr int SizeOfDrawingPaper = 101;
    constexpr int SizeOfColoredPaper = 10;

    vector<vector<int>> DrawingPaper(SizeOfDrawingPaper, vector<int>(SizeOfDrawingPaper, 0));

    int NumberOfColoredPapers; // 1~100
    cin >> NumberOfColoredPapers;

    for (int i = 0; i < NumberOfColoredPapers; i++)
    {
        int StartCol, StartRow; // X coordinate, Y coordinate
        cin >> StartCol >> StartRow;
        for (int Row = StartRow; Row < StartRow + SizeOfColoredPaper; Row++)
        {
            for (int Col = StartCol; Col < StartCol + SizeOfColoredPaper; Col++)
            {
                DrawingPaper[Row][Col] = 1;
            }
        }
    }

    int TotalArea {0};
    for (int Row = 0; Row < SizeOfDrawingPaper; Row++)
    {
        for (int Col = 0; Col < SizeOfDrawingPaper; Col++)
        {
            TotalArea += DrawingPaper[Row][Col];
        }
    }

    cout << TotalArea << endl;
}