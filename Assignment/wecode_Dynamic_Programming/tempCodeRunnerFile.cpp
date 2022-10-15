#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct sach
{
	ll val;
	ll page;
};

int main()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> dp(n, vector<ll>(m + 1));
	vector<sach> b(n);

	for (ll i = 0; i < n; i++)
		cin >> b[i].val;
	for (ll i = 0; i < n; i++)
		cin >> b[i].page;

	for (ll j = 1; j <= m; j++)
	{
		if (j >= b[0].val)
			dp[0][j] = b[0].page;
	}
	for (ll i = 1; i < n; i++)
		for (ll j = 1; j <= m; j++)
		{
			ll k = 0;
			if (j >= b[i].val)
				k = b[i].page + dp[i - 1][j - b[i].val];
			dp[i][j] = max(dp[i - 1][j], k);
		}
	cout << dp[n - 1][m] << endl;
	return 0;
}