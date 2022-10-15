#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
struct bd
{
	int x1, x2, h;
};

int main()
{

	int n;
	cin >> n;
	vector<bd> T(n);
	int x = 0;
	for (bd &i : T)
	{
		cin >> i.x1 >> i.x2 >> i.h;
		x = max(x, i.x2);
	}
	vector<int> Ox(x + 2, 0);
	for (bd i : T)
		for (int j = i.x1; j <= i.x2; j++)
			Ox[j] = max(Ox[j], i.h);
	if (Ox[0] != 0)
		cout << 0 << " " << Ox[0] << endl;
	for (int i = 0; i < x + 1; i++)
	{
		if (Ox[i] < Ox[i + 1])
			cout << i + 1 << " " << Ox[i + 1] << endl;
		else if (Ox[i] > Ox[i + 1])
			cout << i << " " << Ox[i + 1] << endl;
		else if (Ox[i + 1] == 0 && Ox[i] != 0)
			cout << i << " " << 0 << endl;
	}

	return 0;
}