#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const int CurrentNumberOfDwarves  = 9;
    const int OriginalNumberOfDwarves = 7;
    const int TargetSum               = 100;

    vector<int> HeightOfCurrentNumberOfDwarves(CurrentNumberOfDwarves, 0); // 1~100
    for (auto& Element : HeightOfCurrentNumberOfDwarves)
    {
        cin >> Element;
    }

    sort(HeightOfCurrentNumberOfDwarves.begin(), HeightOfCurrentNumberOfDwarves.end()); // Sort for combination

    vector<int> Combination; // 0, 0, 0, 0, 0, 0, 0, 1, 1
    for (int i = 0; i < CurrentNumberOfDwarves; i++)
    {
        if (i < OriginalNumberOfDwarves)
        {
            Combination.push_back(0);
        }
        else
        {
            Combination.push_back(1);
        }
    }

    do
    {
        int         Sum {0};
        vector<int> HeightOfOriginalNumberOfDwarves;

        for (int i = 0; i < CurrentNumberOfDwarves; i++)
        {
            if (Combination[i] == 0)
            {
                Sum += HeightOfCurrentNumberOfDwarves[i];
                HeightOfOriginalNumberOfDwarves.push_back(HeightOfCurrentNumberOfDwarves[i]);
            }
        }

        if (Sum == TargetSum)
        {
            for (const auto& Height : HeightOfOriginalNumberOfDwarves)
            {
                cout << Height << endl;
            }
            return 0;
        }
    }
    while (next_permutation(Combination.begin(), Combination.end()));
}
