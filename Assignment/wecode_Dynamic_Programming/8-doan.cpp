#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct subj
{
    ll st;
    ll en;
    ll tchi;
};
bool endtime(subj a, subj b)
{
    return a.en < b.en;
}
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    vector<subj> subs(n);
    for (ll i = 0; i < n; i++)
        cin >> subs[i].st >> subs[i].en >> subs[i].tchi;
    sort(subs.begin(), subs.end(), endtime);
    map<ll, ll> dp;
    dp[0] = 0;
    for (ll i = 0; i < subs.size(); i++)
    {
        auto t = dp.lower_bound(subs[i].st);
		t--;
        ll k = subs[i].tchi + t->second;
        ans = max(ans,k);
        dp[subs[i].en] = ans;
    }
    for (auto &i : dp)
    {
        cout << i.first << "|" << i.second << endl;
    }

    cout << ans << endl;
    return 0;
}