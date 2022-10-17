#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool ktdoixung(string chuoi, int j, int k)
{
	while (j < k)
	{
		if (chuoi[j] != chuoi[k])
			return false;
		j++;
		k--;
	}
	return true;
}
void ktchuoidoixung(vector<vector<string>> &result, vector<string> &str, int i, int n, string chuoi)
{
	if (i >= n)
	{
		result.push_back(str);
		return;
	}
	for (int j = i; j < n; j++)
	{
		if (ktdoixung(chuoi, i, j))
		{
			str.push_back(chuoi.substr(i, j - i + 1));
			ktchuoidoixung(result, str, j + 1, n, chuoi);
			str.pop_back();
		}
	}
}

int main()
{
	string chuoi;
	cin >> chuoi;
	int n = chuoi.length();

	vector<vector<string>> result;
	vector<string> str;

	ktchuoidoixung(result, str, 0, n, chuoi);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
