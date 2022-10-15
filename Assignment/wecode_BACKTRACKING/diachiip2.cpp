#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
string ip;
int dot[4] = {};
const int n = 3;
int is_valid(string ip)
{
	// Splitting by "."
	vector<string> ips;
	string ex = "";
	for (int i = 0; i < ip.size(); i++)
	{
		if (ip[i] == '.')
		{
			ips.push_back(ex);
			ex = "";
		}
		else
		{
			ex = ex + ip[i];
		}
	}
	ips.push_back(ex);
	for (int i = 0; i < ips.size(); i++)
	{
		// cout << ips[i] <<endl;
		if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255)
			return 0;

		if (ips[i].length() > 1 && stoi(ips[i]) == 0)
			return 0;

		if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')
			return 0;
	}
	return 1;
}

void convert(int i)
{
	for (int j = 1; j < 4; j++)
	{
		if ((j + 1 + dot[i - 1]) <= ip.size())
		{
			dot[i] = j + 1 + dot[i - 1];
			// cout << dot[i];
			ip = ip.substr(0, j + dot[i - 1]) + "." + ip.substr(j + dot[i - 1]);
			// cout << ip << endl;
			if (i < n)
			{
				convert(i + 1);
			}
			else if(is_valid(ip))
			{
				cout << ip << '\n';
			}
			dot[i] = 0;
			ip = ip.substr(0, j + dot[i - 1]) + ip.substr(j + dot[i - 1] + 1);
		}
	}
	return;
}
int main()
{
	cin >> ip;
	convert(1);
	return 0;
}