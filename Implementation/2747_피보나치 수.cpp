#include <iostream>
#include <vector>

using namespace std;

int FibonacciTopDown(int N, vector<int>& Memorization)
{
	if (Memorization[N] != 0)
		return Memorization[N];
	else
	{
		Memorization[N] = FibonacciTopDown(N - 1, Memorization) + FibonacciTopDown(N - 2, Memorization);
		return Memorization[N];
	}
}

int FibonacciBottomUp(int N)
{
	vector<int> FibonacciSet(N + 1, 0);
	FibonacciSet[0] = 0;
	FibonacciSet[1] = 1;

	for (int i = 2; i < N + 1; i++)
	{
		FibonacciSet[i] = FibonacciSet[i - 1] + FibonacciSet[i - 2];
	}

	return FibonacciSet[N];
}

int main()
{
	int N; // 2 ~ 45
	cin >> N;

	// Inital value 0, 1, 1
	vector<int> Memorization(N + 1, 0);
	Memorization[0] = 0;
	Memorization[1] = 1;
	Memorization[2] = 1;
	cout << FibonacciTopDown(N, Memorization) << endl;

	// Inital value 0, 1
	cout << FibonacciBottomUp(N) << endl;

	return 0;
}