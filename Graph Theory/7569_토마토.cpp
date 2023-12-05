#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <cmath>

using namespace std;

#define RIPE     1
#define UNRIPE   0
#define NOTOMATO -1

int main()
{
    int BoxCol, BoxRow; // 2~100
    int BoxHeight;      // 1~100
    cin >> BoxCol >> BoxRow >> BoxHeight;

    vector<vector<vector<int>>> TomatoBox(BoxHeight, vector<vector<int>>(BoxRow, vector<int>(BoxCol, 0)));

    int UnripeCount {0};

    queue<tuple<int, int, int, int>> Waiting; // Height, Row, Col, Day
    for (int Height = 0; Height < BoxHeight; Height++)
    {
        for (int Row = 0; Row < BoxRow; Row++)
        {
            for (int Col = 0; Col < BoxCol; Col++)
            {
                int TomatoCondition;
                cin >> TomatoCondition;
                TomatoBox[Height][Row][Col] = TomatoCondition;

                switch (TomatoCondition)
                {
                    case RIPE:
                        Waiting.push({Height, Row, Col, 0});
                        break;

                    case UNRIPE:
                        UnripeCount++;
                        break;
                }
            }
        }
    }

    int AllTomatoesRipenDay {0};
    if (UnripeCount == 0)
    {
        cout << AllTomatoesRipenDay << endl;
    }
    else
    {
        vector<tuple<int, int, int>> DirectionSet {
            { 0,  0,  1},
            { 0,  0, -1},
            { 0,  1,  0},
            { 0, -1,  0},
            { 1,  0,  0},
            {-1,  0,  0}
        }; // Height, Row, Col

        while (Waiting.empty() == false)
        {
            tuple<int, int, int, int> Current = Waiting.front();
            Waiting.pop();

            AllTomatoesRipenDay = max(AllTomatoesRipenDay, get<3>(Current));

            for (const auto& Dir : DirectionSet)
            {
                int NextHeight = get<0>(Current) + get<0>(Dir);
                int NextRow    = get<1>(Current) + get<1>(Dir);
                int NextCol    = get<2>(Current) + get<2>(Dir);
                int NextDay    = get<3>(Current) + 1;

                if ((NextHeight >= 0 && NextHeight < BoxHeight) &&
                    (NextRow >= 0 && NextRow < BoxRow) &&
                    (NextCol >= 0 && NextCol < BoxCol) &&
                    TomatoBox[NextHeight][NextRow][NextCol] == UNRIPE)
                {
                    TomatoBox[NextHeight][NextRow][NextCol] = RIPE;
                    UnripeCount--;
                    Waiting.push({NextHeight, NextRow, NextCol, NextDay});
                }
            }
        }

        AllTomatoesRipenDay = (UnripeCount != 0 ? -1 : AllTomatoesRipenDay);

        cout << AllTomatoesRipenDay << endl;
    }
}