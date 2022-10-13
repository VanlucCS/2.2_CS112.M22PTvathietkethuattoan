#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> ans;
vector<pair<int, int>> jobs;
vector<int> totaltime;

void Scheduling(int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = 0;
        for (int j = 1; j < totaltime.size(); j++)
            if (totaltime[j] < totaltime[min])
                min = j;
        ans[jobs[i].second] = min;
        totaltime[min] += jobs[i].first;
    }
    return;
}
int main()
{
    int n;
    int k;
    cin >> n >> k;

    ans.resize(n);
    totaltime.resize(k);
    for (int i = 0; i < n; i++)
    {
        int time;
        cin >> time;
        jobs.push_back({time, i});
    }
    sort(jobs.begin(), jobs.end(), std::greater<>());
    Scheduling(n);
    for (int i = 0; i < n; i++)
        cout<<ans[i]<<" ";
    return 0;
}
