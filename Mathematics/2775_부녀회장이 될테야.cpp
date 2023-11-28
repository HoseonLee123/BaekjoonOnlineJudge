#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int TotalTestCase;
    cin >> TotalTestCase;

    for (int TestCase = 0; TestCase < TotalTestCase; TestCase++)
    {
        // Floor starts from 0.
        // Number starts from 1.
        // 1 <= TargetFloor, TargetNumber <= 14
        int TargetFloor, TargetNumber;
        cin >> TargetFloor >> TargetNumber;

        vector<vector<int>> Apartment(TargetFloor + 1, vector<int>(TargetNumber + 1, 0));

        // Initialize Floor 0: 0, 1, 2, 3, 4, 5 ...
        for (int Number = 1; Number < Apartment[0].size(); Number++)
        {
            Apartment[0][Number] = Number;
        }

        for (int Floor = 1; Floor < Apartment.size(); Floor++)
        {
            for (int Number = 1; Number < Apartment[Floor].size(); Number++)
            {
                int Sum = 0;
                for (int DownstairsNumber = 1; DownstairsNumber <= Number; DownstairsNumber++)
                {
                    Sum += Apartment[Floor - 1][DownstairsNumber];
                }
                Apartment[Floor][Number] = Sum;
            }
        }

        cout << Apartment[TargetFloor][TargetNumber] << endl;
    }

    return 0;
}