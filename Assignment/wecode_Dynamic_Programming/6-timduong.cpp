#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<vector<char>> map(n, vector<char>(n, ' '));
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = 1;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
        {
            if (map[i][j] == '*')
                continue;
            ll k = 0;
            if (i - 1 >= 0)
                if (map[i - 1][j] != '*')
                    k += dp[i - 1][j];
            if (j - 1 >= 0)
                if (map[i][j - 1] != '*')
                    k += dp[i][j - 1];

            k %= (ll(1e9 + 7));
            if (!(i == 0 && j == 0))
                dp[i][j] = k;
        }
    cout << dp[n - 1][n - 1] << endl;
  
    return 0;
}