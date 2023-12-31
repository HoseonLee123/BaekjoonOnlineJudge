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

		vector<int> MinOperationCount(X + 1, 0);
		for (int i = 2; i < X + 1; i++)
		{
			int Sub1Count = MinOperationCount[i - 1] + 1;
			int Div2Count = INT32_MAX;
			int Div3Count = INT32_MAX;

			if (i % 2 == 0)
			{
				Div2Count = MinOperationCount[i / 2] + 1;
			}

			if (i % 3 == 0)
			{
				Div3Count = MinOperationCount[i / 3] + 1;
			}

			MinOperationCount[i] = min({ Sub1Count, Div2Count, Div3Count });
		}

		cout << MinOperationCount[X] << endl;
	}




	return 0;
}
