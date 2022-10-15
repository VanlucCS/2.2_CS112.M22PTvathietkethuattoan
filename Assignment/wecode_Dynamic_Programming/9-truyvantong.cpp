#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> val(n);
    vector<ll> dp(n);
    for (ll i = 0; i < n; i++)
        cin >> val[i];
    dp[0] = val[0];
    for (ll i = 1; i < n; i++)
        dp[i] = dp[i - 1] + val[i];

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
            cout << dp[b - 1] << endl;
        else
            cout << dp[b - 1] - dp[a - 2] << endl;
    }
    return 0;
}