#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> ans;
vector<vector<int>> jobs;
vector<int> totaltime;

void Scheduling(int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        vector<int> temp = totaltime;
        int min_total = 0;
        for (int j = 0; j < k; j++)
            if (jobs[j][i] != -1)
            {
                min_total = j;
                break;
            }
                
    // tim may co tong thoi gian thuc hien nho nhat co the thuc hien cong viec
        for (int j = 0; j < k; j++)
        {
            if (jobs[j][i] != -1)
            {
                temp[j] += jobs[j][i];
                if (temp[j] < temp[min_total])
                    min_total = j;
            }
        }
        totaltime[min_total] += jobs[min_total][i];
        ans[i] = min_total;
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
    jobs.resize(k);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
        {
            int time;
            cin >> time;
            jobs[i].push_back(time);
        }
    Scheduling(n, k);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
