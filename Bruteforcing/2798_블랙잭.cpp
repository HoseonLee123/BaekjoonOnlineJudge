#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int NumberOfCards; // 3~100
    int TargetSum;     // 10~300,000
    cin >> NumberOfCards >> TargetSum;

    vector<int> Card(NumberOfCards, 0); // 1~100,000
    for (auto& Element : Card)
    {
        cin >> Element;
    }

    int FirstCard {0}, SecondCard {0}, Thirdcard {0};
    int MaxSum {0};
    for (int First = 0; First < NumberOfCards - 2; First++)
    {
        FirstCard = Card[First];
        for (int Second = First + 1; Second < NumberOfCards - 1; Second++)
        {
            SecondCard = Card[Second];
            for (int Third = Second + 1; Third < NumberOfCards; Third++)
            {
                Thirdcard = Card[Third];

                int CurrentSum = FirstCard + SecondCard + Thirdcard;
                if (CurrentSum <= TargetSum)
                {
                    MaxSum = max(MaxSum, CurrentSum);
                }
            }
        }
    }

    cout << MaxSum << endl;
}