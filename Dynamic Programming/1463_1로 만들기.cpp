#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("Input/1463.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int X; // 1 ~ 10^6
		InputFile >> X;

		vector<int> CountTable(X + 1, 0);
		for (int i = 2; i < X + 1; i++)
		{
			int Plus1 = CountTable[i - 1] + 1;
			int Mul2 = INT32_MAX;
			int Mul3 = INT32_MAX;

			if (i % 2 == 0)
			{
				Mul2 = CountTable[i / 2] + 1;
			}

			if (i % 3 == 0)
			{
				Mul3 = CountTable[i / 3] + 1;
			}

			CountTable[i] = min({ Plus1, Mul2, Mul3 });
		}

		cout << CountTable[X] << endl;
	}




	return 0;
}
