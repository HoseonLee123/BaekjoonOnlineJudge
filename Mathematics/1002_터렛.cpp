#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("Input/1002.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int JoX, JoY, JoRadius, BaekX, BaekY, BaekRadius;
		InputFile >> JoX >> JoY >> JoRadius >> BaekX >> BaekY >> BaekRadius;

		int SumRadius = JoRadius + BaekRadius;
		int DiffRadius = abs(JoRadius - BaekRadius);
		double DistanceBetweenCenters = sqrt(pow(JoX - BaekX, 2) + pow(JoY - BaekY, 2));

		// Two circles are idential.
		if (DiffRadius == 0 && DistanceBetweenCenters == 0)
		{
			cout << -1 << '\n';
		}
		// No contact -> outside.
		else if (SumRadius < DistanceBetweenCenters)
		{
			cout << 0 << '\n';
		}
		// No contact -> one circle contains another circle.
		else if (DiffRadius > DistanceBetweenCenters)
		{
			cout << 0 << '\n';
		}
		// No contanct -> same center but different radius.
		else if (DiffRadius > 0 && DistanceBetweenCenters == 0)
		{
			cout << 0 << '\n';
		}
		// 1 contact -> circumscription
		else if (SumRadius == DistanceBetweenCenters)
		{
			cout << 1 << '\n';
		}
		// 1 contanct -> inscription
		else if (DiffRadius == DistanceBetweenCenters)
		{
			cout << 1 << '\n';
		}
		// 2 contact
		else if (DistanceBetweenCenters > DiffRadius && DistanceBetweenCenters < SumRadius)
		{
			cout << 2 << '\n';
		}
	}

	return 0;
}