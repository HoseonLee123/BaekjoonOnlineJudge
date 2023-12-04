#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(const vector<vector<int>>& FamilyMap,
        vector<bool>&              Discovered,
        vector<int>&               Distance,
        const int&                 NumberOfPersons,
        const int&                 TargetStart,
        const int&                 TargetEnd)
{
    queue<int> Waiting;
    Waiting.push(TargetStart);
    Discovered[TargetStart] = true;
    Distance[TargetStart]   = 0;

    while (Waiting.empty() == false)
    {
        int Present = Waiting.front();
        Waiting.pop();

        for (int Next = 1; Next < NumberOfPersons + 1; Next++)
        {
            // If the present and next has no connection, continue.
            if (FamilyMap[Present][Next] == 0)
                continue;

            // If the next has been discovered already, continue.
            if (Discovered[Next])
                continue;

            Waiting.push(Next);
            Discovered[Next] = true;
            Distance[Next]   = Distance[Present] + 1;

            if (Next == TargetEnd)
            {
                return Distance[Next];
            }
        }
    }

    // No connection
    return -1;
}

int main()
{
    int NumberOfPersons; // 1~100
    int TargetStart, TargetEnd;
    int NumberOfChildParentRelation;

    cin >> NumberOfPersons >> TargetStart >> TargetEnd >> NumberOfChildParentRelation;

    vector<pair<int, int>> ChildParentRelation;
    for (int i = 0; i < NumberOfChildParentRelation; i++)
    {
        int Child {0};
        int Parent {0};
        cin >> Child >> Parent;
        ChildParentRelation.push_back({Child, Parent});
    }

    vector<vector<int>> FamilyMap(NumberOfPersons + 1, vector<int>(NumberOfPersons + 1, 0));
    for (int i = 0; i < NumberOfChildParentRelation; i++)
    {
        FamilyMap[ChildParentRelation[i].first][ChildParentRelation[i].second] = 1;
        FamilyMap[ChildParentRelation[i].second][ChildParentRelation[i].first] = 1;
    }

    vector<bool> Discovered(NumberOfPersons + 1, false);
    vector<int>  Distance(NumberOfPersons + 1, -1);

    cout << BFS(FamilyMap, Discovered, Distance, NumberOfPersons, TargetStart, TargetEnd) << endl;
}