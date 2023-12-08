#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <queue>
#include <tuple>
#include <unordered_set>

using namespace std;

int                 BoardRow, BoardCol; // 1~20
int                 Answer {1};
vector<vector<int>> Board;

vector<bool>                          VisitedAlphabetForDFS(128, false);
vector<vector<unordered_set<string>>> PathBundleForBFS;

vector<pair<int, int>> DirectionBundle {
    { 0,  1},
    { 0, -1},
    { 1,  0},
    {-1,  0}
};

int DFS(const int& CurrentRow, const int& CurrentCol, int& MovingCount);
int BFS();

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

    // DFS
    // int MovingCount                    = 1;
    // VisitedAlphabetForDFS[Board[0][0]] = true;
    // cout << DFS(0, 0, MovingCount) << endl;

    // BFS
    PathBundleForBFS = vector<vector<unordered_set<string>>>(BoardRow, vector<unordered_set<string>>(BoardCol));
    cout << BFS() << endl;
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
            (VisitedAlphabetForDFS[Board[NextRow][NextCol]] == false))
        {
            // Backtracking Technique
            VisitedAlphabetForDFS[Board[NextRow][NextCol]] = true;
            MovingCount++;
            DFS(NextRow, NextCol, MovingCount);
            VisitedAlphabetForDFS[Board[NextRow][NextCol]] = false;
            MovingCount--;
        }
    }

    return Answer;
}

int BFS()
{
    // Intial data setting
    queue<tuple<int, int, string>> Waiting;
    string                         StartString;
    StartString.push_back(static_cast<char>(Board[0][0]));
    Waiting.push({0, 0, StartString});
    PathBundleForBFS[0][0].insert(StartString);

    while (Waiting.empty() == false)
    {
        int    CurrentRow  = get<0>(Waiting.front());
        int    CurrentCol  = get<1>(Waiting.front());
        string CurrentPath = get<2>(Waiting.front());
        Waiting.pop();

        Answer = max(Answer, static_cast<int>(CurrentPath.size()));

        for (const auto& Dir : DirectionBundle)
        {
            int NextRow = CurrentRow + Dir.first;
            int NextCol = CurrentCol + Dir.second;

            if ((NextRow >= 0 && NextRow < BoardRow) &&
                (NextCol >= 0 && NextCol < BoardCol))
            {
                string NextAlphabet;
                NextAlphabet.push_back(static_cast<char>(Board[NextRow][NextCol]));
                unordered_set<string> NextPathBundle = PathBundleForBFS[NextRow][NextCol];
                string                NextPath       = CurrentPath + NextAlphabet;

                // If the next alphabet is not included in the current path.
                // If the next path is not included in the next path bundle. In other words, thin out duplicates of the same path.
                if (CurrentPath.find(NextAlphabet) != -1)
                    continue;
                if (NextPathBundle.find(NextPath) != NextPathBundle.end())
                    continue;

                Waiting.push({NextRow, NextCol, NextPath});
                PathBundleForBFS[NextRow][NextCol].insert(NextPath);
            }
        }
    }

    return Answer;
}