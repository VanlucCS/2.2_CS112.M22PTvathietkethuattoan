#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int n;
vector<string> ans;
map<string, vector<pair<string, int>>> D;
int min_length = 99999;
void input(int n)
{
    string x, y;
    int z;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        D[x].push_back({y, z});
    }
}
void Heuristic(int u, int length, vector<string> temp, string str)
{
    for (int i = 0; i < D[str].size(); i++)
    {
        int flag = 0;
        for (int k = 0; k < temp.size(); k++)
            if (D[str][i].first == temp[k])
                flag = 1;
        if (flag == 1)
            continue;
        length += D[str][i].second;
        if (length > min_length)
        {
            length -= D[str][i].second;
            continue;
        }
        temp.push_back(D[str][i].first);
        if (u == n - 1)
        {
            int y = 1;
            for (int j = 0; j < D[D[str][i].first].size(); j++)
            {
                if (D[D[str][i].first][j].first == temp[0])
                {
                    y = j;
                    break;
                }
            }
            if (length + D[D[str][i].first][y].second < min_length)
            {

                ans = temp;
                min_length = length + D[D[str][i].first][y].second;
            }
        }
        else if (u < n - 1)
        {
            Heuristic(u + 1, length, temp, D[str][i].first);
            temp.pop_back();
            length -= D[str][i].second;
        }
    }
    return;
}

int main()
{
    int o;
    string k;
    cin >> o >> k;
    input(o);
    n = D.size();
    int length = 0;
    vector<string> temp;
    temp.push_back(k);
    Heuristic(1, length, temp, k);
    ans.push_back(ans[0]);
    for (int k = 0; k < ans.size(); k++)
        cout << ans[k] << " ";
    cout << endl;
    return 0;
}