#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("input/2839.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int Sugar; // 3 ~ 5000
		InputFile >> Sugar;

		int TotalBag = 0;
		int Quotient = Sugar / 5;

		for (; Quotient >= 0; Quotient--)
		{
			int Remainder = Sugar - Quotient * 5;
			if (Remainder % 3 == 0)
			{
				TotalBag += Quotient;
				TotalBag += (Remainder / 3);
				break;
			}
		}

		if (TotalBag == 0)
		{
			cout << "#" << TestCase << " " << -1 << endl;
		}
		else
		{
			cout << "#" << TestCase << " " << TotalBag << endl;
		}
	}




	return 0;
}
