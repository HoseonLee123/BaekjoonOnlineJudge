#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("input/2606.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int NumberOfComputers; // 1~100
		int NumberOfNetworkConnetions;

		InputFile >> NumberOfComputers >> NumberOfNetworkConnetions;
		NumberOfComputers++;

		vector<vector<bool>> Network(NumberOfComputers, vector<bool>(NumberOfComputers, false));
		for (int i = 0; i < NumberOfNetworkConnetions; i++)
		{
			int Row, Col;
			InputFile >> Row >> Col;
			Network[Row][Col] = true;
			Network[Col][Row] = true;
		}

		vector<bool> Infected(NumberOfComputers, false);
		queue<int> Target;

		int FirstInfectedComputerNumber = 1;
		Target.push(FirstInfectedComputerNumber);
		Infected[FirstInfectedComputerNumber] = true;
		int NumberOfInfectedComputers = 0;

		while (Target.empty() == false)
		{
			int InfectedComputerNumber = Target.front();
			Target.pop();

			for (int NextTarget = 1; NextTarget < NumberOfComputers; NextTarget++)
			{
				// If there's no connection, continue.
				if (Network[InfectedComputerNumber][NextTarget] == false)
					continue;
				// If the NextTarget has been infected already, continue.
				if (Infected[NextTarget] == true)
					continue;

				Target.push(NextTarget);
				Infected[NextTarget] = true;
				NumberOfInfectedComputers++;
			}
		}

		cout << "#" << TestCase << " " << NumberOfInfectedComputers << endl;
	}

	return 0;
}