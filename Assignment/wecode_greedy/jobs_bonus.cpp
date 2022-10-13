#include <iostream>
// #include <bits/stdc++.h>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> ans;
vector<int> ans_totaltime;
vector<int> jobs;
int maxx = 999999;
int maxtime(vector<int> totaltime)
{
    int max = 0;
    for (int i = 1; i < totaltime.size(); i++)
        if (totaltime[max] < totaltime[i])
            max = i;
    return totaltime[max];
}
void BT_Scheduling(int n, int k, vector<int> schedule,
                   vector<int> totaltime)
{
    for (int i = 0; i < k; i++)
    {
        totaltime[i] += jobs[n];
        schedule[n] = i;
        if (maxtime(totaltime) > maxx)
        {
            totaltime[i] -= jobs[n];
            continue;
        }
        if (n == jobs.size() - 1)
        {
            if (maxtime(ans_totaltime) > maxtime(totaltime))
            {
                ans_totaltime = totaltime;
                ans = schedule;
                maxx = maxtime(ans_totaltime);
            }
        }
        else if (n < jobs.size() - 1)
        {
            BT_Scheduling(n + 1, k, schedule, totaltime);
            totaltime[i] -= jobs[n];
        }
    }
    return;
}
int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> schedule;
    vector<int> totaltime;
    vector<int> temp_ans;
    ans.resize(n);
    schedule.resize(n);
    totaltime.resize(k);
    ans_totaltime.resize(k, 99999);
    for (int i = 0; i < n; i++)
    {
        int time;
        cin >> time;
        jobs.push_back(time);
    }
    BT_Scheduling(0, k, schedule, totaltime);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " " << endl;
    return 0;
}