#include <iostream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;
using std::string;
using std::vector;

int main()
{
    int Digit; // 1~90
    cin >> Digit;

    vector<vector<long long>> PinaryNumber(Digit + 1, vector<long long>(2, 0));
    PinaryNumber[1][0] = 0;
    PinaryNumber[1][1] = 1;

    for (int TargetDigit = 2; TargetDigit < Digit + 1; TargetDigit++)
    {
        PinaryNumber[TargetDigit][0] = PinaryNumber[TargetDigit - 1][0] + PinaryNumber[TargetDigit - 1][1];
        PinaryNumber[TargetDigit][1] = PinaryNumber[TargetDigit - 1][0];
    }

    cout << PinaryNumber[Digit][0] + PinaryNumber[Digit][1] << endl;
}