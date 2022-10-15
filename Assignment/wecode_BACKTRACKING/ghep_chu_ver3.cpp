#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
vector<string> board;
string word;
bool ans = false;
vector<pair<int, int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
bool islocation(int x, int y)
{
	return 0 <= x && x < board.size() && 0 <= y && y < board[0].length();
}
void giai_do(vector<vector<int>> check, int i, int o, int p)
{
	if (ans == true)
		return;
	for (int t = 0; t < 8; t++)
	{
		int j = 0, k = 0;
		j = o + dir[t].first;
		k = p + dir[t].second;
		if (!islocation(j, k))
			continue;

		if (board[j][k] == word[i] && check[j][k] == 0)
		{
			check[j][k] = 1;
			if (i == word.length() - 1)
			{
				ans = true;
				cout << "true";
				return;
			}
			else if (ans == false)
			{
				giai_do(check, i + 1, j, k);
				if (ans == true)
					return;
			}
			check[j][k] = 0;
		}

		if (ans == true)
			return;
	}
	return;
}

int main()
{
	string input;
	cin >> word;
	do
	{
		cin >> input;
		board.push_back(input);
	} while (input != ".");
	vector<vector<int>> check(board.size(), vector<int>(board[0].size(), 0));
	for (int j = board.size() - 1; j >= 0; j--)
	{
		for (int k = board[j].size() - 1; k >= 0; k--)
		{
			if (word[0] == board[j][k])
			{
				check[j][k] = 1;
				giai_do(check, 1, j, k);
				check[j][k] = 0;
			}
			if (ans == true)
				break;
		}
		if (ans == true)
			break;
	}
	if (ans == false)
		cout << "false";
	return 0;
}