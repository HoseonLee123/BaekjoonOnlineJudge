#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int                    TotalTestCase;              // 1~50
int                    NumberOfConvenienceStores;  // 0~100
int                    StartX, StartY, EndX, EndY; // -32768~32767
vector<pair<int, int>> ConveniceStoresXY;
void                   BFS();

int main()
{
    cin >> TotalTestCase;
    for (int TestCase = 0; TestCase < TotalTestCase; TestCase++)
    {
        cin >> NumberOfConvenienceStores;
        cin >> StartX >> StartY;
        ConveniceStoresXY = vector<pair<int, int>>(NumberOfConvenienceStores);
        for (int i = 0; i < NumberOfConvenienceStores; i++)
        {
            cin >> ConveniceStoresXY[i].first;
            cin >> ConveniceStoresXY[i].second;
        }
        cin >> EndX >> EndY;

        BFS();
    }
}

void BFS()
{
    queue<pair<int, int>> Waiting;
    Waiting.push({StartX, StartY});
    vector<bool> Visited(NumberOfConvenienceStores, false);

    while (Waiting.empty() == false)
    {
        int CurrentX = Waiting.front().first;
        int CurrentY = Waiting.front().second;
        Waiting.pop();

        if (abs(CurrentX - EndX) + abs(CurrentY - EndY) <= 1000)
        {
            cout << "happy" << endl;
            return;
        }

        for (int i = 0; i < NumberOfConvenienceStores; i++)
        {
            if (Visited[i] == false)
            {
                int NextX = ConveniceStoresXY[i].first;
                int NextY = ConveniceStoresXY[i].second;

                if (abs(CurrentX - NextX) + abs(CurrentY - NextY) <= 1000)
                {
                    Waiting.push({NextX, NextY});
                    Visited[i] = true;
                }
            }
        }
    }

    cout << "sad" << endl;
}