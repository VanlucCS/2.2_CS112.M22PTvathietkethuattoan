#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> list(n + 1);
    vector<ll> dp(n + 1);
    vector<ll> mv(n + 1,LLONG_MAX);
    dp[1] = 1;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        cin >> list[i];

    for (int i = 0; i <= n; i++)
    {
        // dp[i] = max(d[i-{k:([i-1]->0)]}?{list[k] <=list[i]}) + 1;
        int l = 0;
        int r = i + 1;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (mv[m] >= list[i])
                r = m;
            else
            {
                l = m + 1;
                dp[i] = 1 + m;
            }
        }
        mv[dp[i]] = min(mv[dp[i]], list[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}