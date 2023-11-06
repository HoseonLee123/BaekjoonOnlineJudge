#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("input/2178.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{

		int Row, Col; // 2~100
		InputFile >> Row >> Col;

		vector<vector<int>> Maze(Row, vector<int>(Col, 0));
		for (int i = 0; i < Row; i++)
		{
			string OneLine;
			InputFile >> OneLine;
			for (int j = 0; j < OneLine.size(); j++)
			{
				Maze[i][j] = (OneLine[j] - '0');
			}
		}

		vector<vector<int>> Discovered(Row, vector<int>(Col, 0));

		queue<pair<int, int>> Waiting;
		int StartRow = 0;
		int StartCol = 0;
		Waiting.push({ StartRow, StartCol });

		Discovered[StartRow][StartCol] = 1;
		vector<pair<int, int>> DirectionSet = { {0, 1},{1, 0},{0, -1},{-1, 0} };

		// BFS
		while (Waiting.empty() == false)
		{
			int CurrentRow = Waiting.front().first;
			int CurrentCol = Waiting.front().second;
			Waiting.pop();

			// Next
			for (const pair<int, int>& Direction : DirectionSet)
			{
				int NextRow = CurrentRow + Direction.first;
				int NextCol = CurrentCol + Direction.second;

				// First condition: if the next is within a range.
				// Second condition: if the next can go.
				// Third condition: if the next has not been discovered yet.
				if (((NextRow >= 0 && NextRow < Row) && (NextCol >= 0 && NextCol < Col)) && (Maze[NextRow][NextCol] == 1) && (Discovered[NextRow][NextCol] == 0))
				{
					Waiting.push({ NextRow,NextCol });
					Discovered[NextRow][NextCol] = Discovered[CurrentRow][CurrentCol] + 1;
				}
			}
		}

		cout << "#" << TestCase << " " << Discovered[Row - 1][Col - 1] << endl;
	}

	return 0;
}