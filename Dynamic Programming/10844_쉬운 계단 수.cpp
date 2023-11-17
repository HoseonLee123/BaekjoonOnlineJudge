#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N; // 1~100
	cin >> N;

	// Value 0~9   0 1 2 3 4 5 6 7 8 9  
	// Index     0 1 2 3 4 5 6 7 8 9 10 11
	// Table N=1 X 0 1 1 1 1 1 1 1 1 1  X (X == 0 padding)
	// Table N=2 X 1 1 2 2 2 2 2 2 2 1  X
	// Table N=3 X 1 3 3 4 4 4 4 4 3 2  X
	vector<vector<long long>> StairsNumberTable(N + 1, vector<long long>(12, 0));
	StairsNumberTable[1] = { 0,0,1,1,1,1,1,1,1,1,1,0 };

	for (int i = 2; i < N + 1; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			StairsNumberTable[i][j] = (StairsNumberTable[i - 1][j - 1] + StairsNumberTable[i - 1][j + 1]) % 1000000000;
		}
	}

	long long TotalStairNumber{ 0 };
	for (const long long& Element : StairsNumberTable[N])
	{
		TotalStairNumber += Element;
	}
	TotalStairNumber %= 1000000000;
	cout << TotalStairNumber << endl;


	return 0;
}