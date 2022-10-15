#include <iostream>
#include <vector>
using namespace std;

int knapsackRecursive(vector<vector<int>> lookupTable, vector<int> profits, int profitsLength, vector<int> weights, int capacity, int currentIndex)
{

	if (capacity <= 0 || currentIndex >= profitsLength || currentIndex < 0)
		return 0;

	if (lookupTable[currentIndex][capacity] != 0)
		return lookupTable[currentIndex][capacity];

	int profit1 = 0;
	if (weights[currentIndex] <= capacity)
		profit1 = profits[currentIndex] + knapsackRecursive(lookupTable, profits, profitsLength, weights,
															capacity - weights[currentIndex], currentIndex + 1);

	int profit2 = knapsackRecursive(lookupTable, profits, profitsLength, weights, capacity, currentIndex + 1);

	lookupTable[currentIndex][capacity] = max(profit1, profit2);
	return lookupTable[currentIndex][capacity];
}

int knapSack(vector<int> profits, int profitsLength, vector<int> weights, int capacity)
{
	vector<vector<int>> lookupTable(
		profitsLength,
		std::vector<int>(capacity + 1, 0));
	return knapsackRecursive(lookupTable, profits, profitsLength, weights, capacity, 0);
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> val(n, 0);
	vector<int> page(n, 0);
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	for (int i = 1; i <= n; i++)
		cin >> page[i];
	cout <<knapSack(page, n, val, m) << endl;
	return 0;
}
