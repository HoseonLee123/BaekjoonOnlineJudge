#include <iostream>
#include <string>
#include <set>

using namespace std;

int NumberOfString, NumberOfCheck; // 1~10,000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> NumberOfString >> NumberOfCheck;

    set<string> StringSet;
    for (int i = 0; i < NumberOfString; i++)
    {
        string Temp;
        cin >> Temp;
        StringSet.insert(Temp);
    }

    int FindingCount {0};
    for (int i = 0; i < NumberOfCheck; i++)
    {
        string Temp;
        cin >> Temp;
        if (StringSet.find(Temp) != StringSet.end())
        {
            FindingCount++;
        }
    }

    cout << FindingCount << '\n';
}