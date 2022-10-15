#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
vector<vector<char>> board;
string word;
bool ans = false;
vector<pair<int, int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
bool isnearby(int i, int j, int k, int l)
{
	for (int o = 0; o < 8; o++)
		if (i + dir[o].first == k && (j + dir[o].second) == l)
			return true;
	return false;
}
void giai_do(vector<vector<int>> check, int i, int o, int p)
{
	for (int j = board.size() - 1; j >= 0; j--)
	{
		if (ans == false)
		{
			for (int k = board[j].size() - 1; k >= 0; k--)
			{
				if (board[j][k] == word[i] && check[j][k] == 0)
				{
					if (i == 0 || isnearby(j, k, o, p))
					{
						check[j][k] = 1;
						if (i == word.length() - 1)
						{
							ans = true;
							cout << "true";
							return;
						}
						else if(ans == false)
						{
							giai_do(check, i + 1, j, k);
							if (ans == true)
								return;
						}
						check[j][k] = 0;
					}
					// if (ans == true)
					// 	return;
				}
				if (ans == true)
					return;
			}
		}
		if (ans == true)
			break;
	}
	if (i == 0 && ans == false)
		cout << "false";
	return;
}

int main()
{
	string input;
	cin >> word;
	int i = 1;
	do
	{
		board.resize(i);
		cin >> input;
		if (input == ".")
			break;
		for (int k = 0; k < input.length(); k++)
			board[i - 1].push_back(input[k]);
		i++;
	} while (input != ".");
	board.resize(i - 1);
	vector<vector<int>> check(board.size(), vector<int>(board[0].size(), 0));
	giai_do(check, 0, 0, 0);
	return 0;
}
