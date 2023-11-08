#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("input/1003.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int N;
		InputFile >> N; // 0 ~ 40

		vector<vector<int>> FibonacciCounting0And1(2, vector<int>(41, 0));
		FibonacciCounting0And1[0][0] = 1;
		FibonacciCounting0And1[0][1] = 0;
		FibonacciCounting0And1[1][0] = 0;
		FibonacciCounting0And1[1][1] = 1;

		for (int i = 2; i < N + 1; i++)
		{
			FibonacciCounting0And1[0][i] = FibonacciCounting0And1[0][i - 1] + FibonacciCounting0And1[0][i - 2];
			FibonacciCounting0And1[1][i] = FibonacciCounting0And1[1][i - 1] + FibonacciCounting0And1[1][i - 2];
		}

		cout << FibonacciCounting0And1[0][N] << " " << FibonacciCounting0And1[1][N] << endl;
	}




	return 0;
}
