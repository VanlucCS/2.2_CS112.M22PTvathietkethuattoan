#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long s;
	cin >> s;
	vector<long long> dp(s + 1, 0);
	dp[0] = 1;
	for (long long S = 1; S <= s; S++)
	{
		for (long long i = 1; i < 7; i++)
		{
			if (S - i >= 0)
			{
				dp[S] += (dp[S - i]);
				dp[S] %=(long long)(1e9+7);
			}
		}
	}
	cout << dp[s] << endl;

	return 0;
}