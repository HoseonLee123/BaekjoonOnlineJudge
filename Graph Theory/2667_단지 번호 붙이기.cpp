#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ifstream InputFile;
	InputFile.open("input/2667.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		int MapSize; // 5~25
		InputFile >> MapSize;

		vector<vector<bool>> ComplexMap(MapSize, vector<bool>(MapSize, false));
		for (int Row = 0; Row < MapSize; Row++)
		{
			string OneLine;
			InputFile >> OneLine;
			for (int Col = 0; Col < MapSize; Col++)
			{
				ComplexMap[Row][Col] = OneLine[Col] - '0';
			}
		}

		vector<vector<int>> ComplexMapNumbering(MapSize, vector<int>(MapSize, 0));

		int Numbering = 1;
		int TotalNumbering = 0;
		vector<int> NumberingSet;
		queue<pair<int, int>> Target;

		vector<pair<int, int>> DirectionSet = { {0, 1},{1, 0},{0, -1},{-1, 0} };

		for (int Row = 0; Row < MapSize; Row++)
		{
			for (int Col = 0; Col < MapSize; Col++)
			{
				// If there's a house and the house has not been numbered yet.
				if (ComplexMap[Row][Col] == true && ComplexMapNumbering[Row][Col] == 0)
				{
					// BFS
					int StartRow = Row;
					int StartCol = Col;
					Target.push({ StartRow,StartCol });
					ComplexMapNumbering[StartRow][StartCol] = Numbering;
					TotalNumbering = 1;

					while (Target.empty() == false)
					{
						int CurrentRow = Target.front().first;
						int CurrentCol = Target.front().second;
						Target.pop();

						for (const pair<int, int>& Direction : DirectionSet)
						{
							int NextRow = CurrentRow + Direction.first;
							int NextCol = CurrentCol + Direction.second;

							// First condition: if the next is within a range.
							// Second condition: if the next is a house.
							// Third condition: if the next has not been numbered yet.
							if (((NextRow >= 0 && NextRow < MapSize) && (NextCol >= 0 && NextCol < MapSize))
								&& ComplexMap[NextRow][NextCol] == true
								&& ComplexMapNumbering[NextRow][NextCol] == 0)
							{
								Target.push({ NextRow,NextCol });
								ComplexMapNumbering[NextRow][NextCol] = Numbering;
								TotalNumbering++;
							}
						}
					}

					NumberingSet.push_back(TotalNumbering);
					Numbering++;
					TotalNumbering = 0;
				}
			}
		}

		sort(NumberingSet.begin(), NumberingSet.end());
		cout << "#" << TestCase << " " << endl;
		cout << NumberingSet.size() << endl;
		for (const int& Numbering : NumberingSet)
		{
			cout << Numbering << endl;
		}
	}

	return 0;
}