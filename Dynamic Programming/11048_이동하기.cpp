#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

int main()
{
    int MazeRow, MazeCol; // 1~1000
    cin >> MazeRow >> MazeCol;

    vector<vector<int>> MazeCandy(MazeRow + 1, vector<int>(MazeCol + 1, 0));
    for (int Row = 1; Row <= MazeRow; Row++)
    {
        for (int Col = 1; Col <= MazeCol; Col++)
        {
            int NumberOfCandies {}; // 1~100
            cin >> NumberOfCandies;
            MazeCandy[Row][Col] = NumberOfCandies;
        }
    }

    vector<vector<int>> MaxCandy(MazeRow + 1, vector<int>(MazeCol + 1, 0));
    for (int Row = 1; Row <= MazeRow; Row++)
    {
        for (int Col = 1; Col <= MazeCol; Col++)
        {   
            // MaxCandy = MazeCandy + the max cumulative candy in three directions
            MaxCandy[Row][Col] = MazeCandy[Row][Col] + max({MaxCandy[Row][Col - 1], MaxCandy[Row - 1][Col - 1], MaxCandy[Row - 1][Col]});
        }
    }

    cout << MaxCandy[MazeRow][MazeCol] << endl;
}