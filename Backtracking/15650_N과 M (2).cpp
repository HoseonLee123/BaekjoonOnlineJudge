#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, TargetCount; // 1 <= TargetCount <= N <= 8 

void DFS(int CurrentCount, int StartIndex, vector<int>& Progression)
{
	if (CurrentCount == TargetCount)
	{
		for (const int& Element : Progression)
		{
			cout << Element << " ";
		}
		cout << '\n';
		return;
	}

	for (int Rep = StartIndex; Rep < N + 1; Rep++)
	{
		Progression[CurrentCount] = Rep;

		DFS(CurrentCount + 1, Rep + 1, Progression);
	}

}

int main()
{
	ifstream InputFile;
	InputFile.open("input/15650.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		InputFile >> N >> TargetCount;

		vector<int> Progression(TargetCount, 0);

		cout << "#" << TestCase << '\n';

		DFS(0, 1, Progression);


	}

	return 0;
}