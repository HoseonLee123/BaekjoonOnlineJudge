#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void DFS(int StartVertex, int NumberOfVertices, vector<bool>& Visited, vector<vector<bool>>& Map)
{
	Visited[StartVertex] = true;
	cout << StartVertex << " ";

	for (int NextVertex = 1; NextVertex < NumberOfVertices; NextVertex++)
	{
		// If there's no edge, continue.
		if (Map[StartVertex][NextVertex] == false)
			continue;

		// If this vertex has not been visited, go next DFS.
		if (Visited[NextVertex] == false)
			DFS(NextVertex, NumberOfVertices, Visited, Map);
	}
}

void BFS(int StartVertex, int NumberOfVertices, vector<bool>& Discovered, vector<vector<bool>>& Map)
{
	queue<int> Waiting;
	Waiting.push(StartVertex);

	Discovered[StartVertex] = true;

	while (Waiting.empty() == false)
	{
		StartVertex = Waiting.front();
		Waiting.pop();
		cout << StartVertex << " ";

		for (int NextVertex = 1; NextVertex < NumberOfVertices; NextVertex++)
		{
			// If there's no edge, continue.
			if (Map[StartVertex][NextVertex] == false)
				continue;

			// If this vertex has been discovered, continue.
			if (Discovered[NextVertex])
				continue;

			// If having passed the previous conditions, push the NextVertex into the Waiting.
			Waiting.push(NextVertex);
			Discovered[NextVertex] = true;
		}
	}
}

int main()
{
	ifstream InputFile;
	InputFile.open("input/1260.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;
	for (int TestCase = 1; TestCase <= TotalTestCase; TestCase++)
	{
		cout << "#" << TestCase << endl;

		int NumberOfVertices, NumberOfEdges, StartVertex;
		InputFile >> NumberOfVertices >> NumberOfEdges >> StartVertex;
		NumberOfVertices++; // Vertex numbers start from 1. 

		vector<vector<bool>> Map(NumberOfVertices, vector<bool>(NumberOfVertices, false));
		for (int i = 0; i < NumberOfEdges; i++)
		{
			int Row, Col;
			InputFile >> Row >> Col;

			Map[Row][Col] = true;
			Map[Col][Row] = true;
		}

		vector<bool> Visited(NumberOfVertices, false);
		DFS(StartVertex, NumberOfVertices, Visited, Map);

		cout << endl;
		vector<bool> Discovered(NumberOfVertices, false);
		BFS(StartVertex, NumberOfVertices, Discovered, Map);

		cout << endl;
	}





	return 0;
}