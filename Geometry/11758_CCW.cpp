#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;


int main()
{
	ifstream InputFile;
	InputFile.open("Input/11758.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int P1x, P1y, P2x, P2y, P3x, P3y; // -10000 ~ 10000, P1 != P2 != P3
		InputFile >> P1x >> P1y >> P2x >> P2y >> P3x >> P3y;

		int Answer = 0;
		int Counterclockwise = 1;
		int Clockwise = -1;
		int Straight = 0;

		// Shoelace formula
		int Sign = (P1x * P2y + P2x * P3y + P3x * P1y) - (P2x * P1y + P3x * P2y + P1x * P3y);
		if (Sign > 0)
		{
			Answer = Counterclockwise;
		}
		else if (Sign < 0)
		{
			Answer = Clockwise;
		}
		else
		{
			Answer = Straight;
		}


		cout << Answer << endl;
	}

	return 0;
}