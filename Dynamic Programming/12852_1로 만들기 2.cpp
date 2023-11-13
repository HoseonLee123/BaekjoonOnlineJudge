#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("Input/12852.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int X; // 1 ~ 10^6
		InputFile >> X;

		vector<int> MinOperationCount(X + 1, 0);
		vector<int> Connection(X + 1, 0);
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

			if (min({ Sub1Count, Div2Count, Div3Count }) == Sub1Count)
			{
				Connection[i] = i - 1;
			}
			else if (min({ Sub1Count, Div2Count, Div3Count }) == Div2Count)
			{
				Connection[i] = i / 2;
			}
			else
			{
				Connection[i] = i / 3;
			}

			MinOperationCount[i] = min({ Sub1Count, Div2Count, Div3Count });
		}

		cout << MinOperationCount[X] << endl;

		int TargetIndex = X;
		cout << X << ' ';
		for (int i = 0; i < MinOperationCount[X]; i++)
		{
			cout << Connection[TargetIndex] << " ";
			TargetIndex = Connection[TargetIndex];
		}
		cout << endl;
	}




	return 0;
}
