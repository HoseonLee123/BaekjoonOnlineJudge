#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("Input/1004.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int DepartureX, DepartureY, ArrivalX, ArrivalY;
		int TotalPlanetarySystems;
		int PlanetarySystemCenterX, PlanetarySystemCenterY, PlanetarySystemRadius;

		InputFile >> DepartureX >> DepartureY >> ArrivalX >> ArrivalY;
		InputFile >> TotalPlanetarySystems;

		int Entry = 0, Exit = 0;
		for (int i = 0; i < TotalPlanetarySystems; i++)
		{
			InputFile >> PlanetarySystemCenterX >> PlanetarySystemCenterY >> PlanetarySystemRadius;

			// Exit
			bool ExitCondition1 = pow(PlanetarySystemCenterX - DepartureX, 2) + pow(PlanetarySystemCenterY - DepartureY, 2) < pow(PlanetarySystemRadius, 2);
			bool ExitCondition2 = pow(PlanetarySystemCenterX - ArrivalX, 2) + pow(PlanetarySystemCenterY - ArrivalY, 2) > pow(PlanetarySystemRadius, 2);
			if (ExitCondition1 && ExitCondition2)
				Entry++;
			
			// Entry
			bool EntryCondition1 = pow(PlanetarySystemCenterX - DepartureX, 2) + pow(PlanetarySystemCenterY - DepartureY, 2) > pow(PlanetarySystemRadius, 2);
			bool EntryCondition2 = pow(PlanetarySystemCenterX - ArrivalX, 2) + pow(PlanetarySystemCenterY - ArrivalY, 2) < pow(PlanetarySystemRadius, 2);
			if (EntryCondition1 && EntryCondition2)
				Entry++;
		}

		cout << Entry + Exit << endl;

	}

	return 0;
}