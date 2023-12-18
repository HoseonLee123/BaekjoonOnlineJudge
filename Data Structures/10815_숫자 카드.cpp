#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int NumberOfCards;       // 1~500,000
    int NumberOfHavingOrNot; // 1~500,000

    cin >> NumberOfCards;
    unordered_set<int> Cards; // -10,000,000~10,000,000
    for (int i = 0; i < NumberOfCards; i++)
    {
        int Temp;
        cin >> Temp;
        Cards.insert(Temp);
    }

    cin >> NumberOfHavingOrNot;
    for (int i = 0; i < NumberOfHavingOrNot; i++)
    {
        int Target;
        cin >> Target;
        auto Result = Cards.find(Target);
        if (Result != Cards.end())
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
}