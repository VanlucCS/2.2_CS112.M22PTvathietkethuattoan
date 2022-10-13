#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
map<string, vector<pair<string, int>>> D;

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
void Heuristic(string str)
{
    vector<string> temp;
    temp.push_back(str);
    while (temp.size() != D.size())
    {
        int min_distance = 99999;
        int idx = -1;
        for (int j = 0; j < D[str].size(); j++)
        {
            int flag = 0;
            for (int k = 0; k < temp.size(); k++)
                if (D[str][j].first == temp[k])
                    flag = 1;
            if (flag == 1)
                continue;
            else
            {
                if (D[str][j].second < min_distance)
                {
                    idx = j;
                    min_distance = D[str][j].second;
                }
            }
        }
        temp.push_back(D[str][idx].first);
        str = D[str][idx].first;
    }
    temp.push_back(temp[0]);
    for (int k = 0; k < temp.size(); k++)
        cout << temp[k] << " ";
    cout<<endl;
    return;
}

int main()
{
    int n;
    string k;
    cin >> n >> k;
    input(n);
    Heuristic(k);
    return 0;
}
