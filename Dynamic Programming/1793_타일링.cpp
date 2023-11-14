#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string TileCount[251];

string NextTileCount(const string& FirstBack, const string& SecondBack)
{
	// TileCount[i] = TileCount[i - 1] + TileCount[i - 2] * 2;
	string First = FirstBack;
	string Second1 = SecondBack;
	string Second2 = SecondBack;

	int Sum = 0;
	string NextTile = "";
	while (!First.empty() || !Second1.empty() || !Second2.empty() || Sum)
	{
		if (!First.empty())
		{
			Sum += First.back() - '0';
			First.pop_back();
		}
		if (!Second1.empty())
		{
			Sum += Second1.back() - '0';
			Second1.pop_back();
		}
		if (!Second2.empty())
		{
			Sum += Second2.back() - '0';
			Second2.pop_back();
		}

		NextTile.push_back(Sum % 10 + '0');

		Sum /= 10;
	}

	reverse(NextTile.begin(), NextTile.end());

	return NextTile;
}


int main()
{
	int N; // 0 ~ 250
	TileCount[0] = "1";
	TileCount[1] = "1";
	for (int i = 2; i < 251; i++)
	{
		TileCount[i] = NextTileCount(TileCount[i - 1], TileCount[i - 2]);
	}

	while (cin >> N)
	{
		cout << TileCount[N] << endl;
	}


	return 0;
}