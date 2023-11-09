#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, TargetCount; // 1 <= TargetCount <= N <= 8

void DFS(int CurrentCount, vector<bool>& Selected, vector<int>& Progression)
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


	for (int Rep = 1; Rep < N + 1; Rep++)
	{
		if (Selected[Rep] == false)
		{
			Progression[CurrentCount]=Rep;
			Selected[Rep] = true;
			DFS(CurrentCount + 1, Selected, Progression);
			Selected[Rep] = false;
		}

	}
}

int main()
{
	ifstream InputFile;
	InputFile.open("input/15649.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		InputFile >> N >> TargetCount;
		vector<bool> Selected(N + 1, false);
		vector<int> Progression(TargetCount,0);

		cout << "#" << TestCase << endl;
		DFS(0, Selected, Progression);

	}

	return 0;
}