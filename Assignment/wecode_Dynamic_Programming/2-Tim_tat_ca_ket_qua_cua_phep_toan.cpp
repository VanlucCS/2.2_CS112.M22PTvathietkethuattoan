#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <climits>
#include <string>
using namespace std;

vector<char> dau;
vector<int> gt;
int cal(int a, char b, int c)
{
    if (b == '+')
        return a + c;
    else if (b == '-')
        return a - c;
    else
        return a * c;
}

vector<int> tinhbieuthuc( int low, int high)
{
    vector<int> ans;

    // 1 ky tu
    if (low == high)
    {
        ans.push_back(gt[low]);
        return ans;
    }
    // 3 ky tu
    if (low == (high - 2))
    {
        int num = cal(gt[low], dau[low + 1], gt[low + 2]);

        ans.push_back(num);
        return ans;
    }

    for (int i = low + 1; i <= high; i += 2)
    {
        vector<int> l = tinhbieuthuc( low, i - 1);
        vector<int> r = tinhbieuthuc( i + 1, high);
        for (int m = 0; m < l.size(); m++)
        {
            for (int n = 0; n < r.size(); n++)
            {
                int val = cal(l[m], dau[i], r[n]);
                ans.push_back(val);
            }
        }
    }
    return ans;
}

int main()
{
    string M;
    cin>>M;
    for (int i = 0; i < M.size(); i++)
    {
        if (M[i] == '+' || M[i] == '-' || M[i] == '*')
        {
            dau.push_back(M[i]);
            gt.push_back(0);
        }
        else
        {
            dau.push_back('/');
            int j = 0;
			while (i < M.size())
			{
				j = j * 10 + M[i] - '0';
				if (i + 1 < M.size() && M[i + 1] >= '0' && M[i + 1] <= '9')
					i++;
				else
					break;
			}
			gt.push_back(j);
        }
    }
    vector<int> ans = tinhbieuthuc(0, dau.size() - 1);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
