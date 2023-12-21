#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int                 NumberOfElements; // 1~20
int                 TargetSum;        // -1,000,000~1,000,000
vector<int>         Sequence;         // -100,000~100,000
int                 NumberOfCases = 0;
vector<vector<int>> AuxiliaryVectorsForCombination;

int main()
{
    cin >> NumberOfElements >> TargetSum;
    for (int i = 0; i < NumberOfElements; i++)
    {
        int Temp;
        cin >> Temp;
        Sequence.push_back(Temp);
    }

    // Create auxiliary vectors for combination(nC1...nCr...nCn)(n = NumberOfElements)
    for (int r = 1; r <= NumberOfElements; r++)
    {
        vector<int> AuxiliaryVector(NumberOfElements, 1);
        for (int i = 0; i < r; i++)
        {
            AuxiliaryVector[i] = 0;
        }
        AuxiliaryVectorsForCombination.push_back(AuxiliaryVector);
    }

    // Execute combination(nC1...nCr...nCn) using auxiliary vectors
    for (int i = 0; i < AuxiliaryVectorsForCombination.size(); i++)
    {
        vector<int> CurrentAuxiliaryVector = AuxiliaryVectorsForCombination[i];
        do
        {
            int Sum {0};
            for (int j = 0; j < NumberOfElements; j++)
            {
                if (CurrentAuxiliaryVector[j] == 0)
                {
                    Sum += Sequence[j];
                }
            }
            if (Sum == TargetSum)
            {
                NumberOfCases++;
            }
        }
        while (next_permutation(CurrentAuxiliaryVector.begin(), CurrentAuxiliaryVector.end()));
    }

    cout << NumberOfCases << endl;
}
