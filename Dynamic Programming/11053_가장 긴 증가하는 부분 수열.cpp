#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int SequenceSize;
    cin >> SequenceSize; // 1~1000

    vector<int> Sequence(SequenceSize + 1, 0);
    for (int i = 1; i < SequenceSize + 1; i++)
    {
        cin >> Sequence[i]; // 1~1000
    }

    vector<int> MaxLength(SequenceSize + 1, 0);
    for (int i = 1; i < SequenceSize + 1; i++)
    {
        int Max = 0;
        for (int j = 0; j < i; j++)
        {
            if (Sequence[j] < Sequence[i])
                Max = max(Max, MaxLength[j]);
        }
        MaxLength[i] = Max + 1;
    }

    cout << *max_element(MaxLength.begin(), MaxLength.end()) << endl;
}