#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("Input/11726.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int N; // 1 ~ 1000
		InputFile >> N; 

		vector<int> TileCount(N + 1, 0);
		TileCount[0] = 1;
		TileCount[1] = 1;
		for (int i = 2; i < N + 1; i++)
		{
			// Divide by 10007 and store the remainder to prevent the overflow problem.
			TileCount[i] = (TileCount[i - 1] + TileCount[i - 2]) % 10007;
		}

		cout << TileCount[N] << endl;
	}



	return 0;
}
