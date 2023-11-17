#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N; // 1~1000
	cin >> N;

	vector<vector<int>> TotalAscendingCount(N + 1, vector<int>(10, 0));
	vector<int> InitializedAscendingCount(10, 1);
	TotalAscendingCount[0] = InitializedAscendingCount;
	TotalAscendingCount[1] = InitializedAscendingCount;

	for (int Row = 2; Row < N + 1; Row++)
	{
		for (int Col = 0; Col < 10; Col++)
		{
			int SumOfBeforeRow{ 0 };
			for (int ColOfBeforeRow = Col; ColOfBeforeRow < 10; ColOfBeforeRow++)
			{
				SumOfBeforeRow += (TotalAscendingCount[Row - 1][ColOfBeforeRow] % 10007);
			}
			TotalAscendingCount[Row][Col] = (SumOfBeforeRow % 10007);
		}
	}

	int AnswerSum{ 0 };
	for (const int& Element : TotalAscendingCount[N])
	{
		AnswerSum += Element;
	}
	cout << AnswerSum % 10007 << endl;


	return 0;
}




