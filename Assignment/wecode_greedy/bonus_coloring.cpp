#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
map<string, vector<string>> Graph;
int maxcolor = 9999;
map<string, int> ans;
int maxx=9999;

void input(int v, int e, vector<pair<string, int>> &color,
           map<string, int> &M,
           map<string, vector<string>> &constraint,
           set<int> &mau)
{

    for (int j = 0; j < v; j++)
    {
        string a;
        cin >> a;
        color.push_back({a, -1});
        constraint[a].push_back(" "); // phan tu rang buoc dau tien la " "
        M[a] = -1;
    }
    string x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
    return;
}

void coloring(int n, vector<pair<string, int>> color,
              map<string, int> M,
              map<string, vector<string>> constraint,
              set<int> mau)
{
    for (int i = 0; i < maxx; i++)
    {
        string dinh = color[n].first;
        int flag = 0;
        for (int j = 1; j < constraint[dinh].size(); j++)
        {
            if (i == M[constraint[dinh][j]])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;
        if (n == color.size() - 1)
        {
            M[dinh] = i;
            mau.insert(i);
            for (int j = 0; j < Graph[dinh].size(); j++)
                constraint[Graph[dinh][j]].push_back(dinh);
            if (mau.size() < maxcolor && maxx >= *--mau.end())
            {
                ans = M;
                maxcolor = mau.size();
                maxx=*--mau.end();
            }
            break;
        }
        else
        {
            M[dinh] = i;
            mau.insert(i);
            for (int j = 0; j < Graph[dinh].size(); j++)
                constraint[Graph[dinh][j]].push_back(dinh);
        }
        if (n < color.size() - 1)
        {
            coloring(n + 1, color, M, constraint, mau);
            for (int j = 0; j < Graph[dinh].size(); j++)
                constraint[Graph[dinh][j]].pop_back();
            mau.erase(i);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<string, int>> color;
    map<string, int> M;
    map<string, vector<string>> constraint;
    set<int> mau;
    input(v, e, color, M, constraint, mau);
    coloring(0, color, M, constraint, mau);
    for (int t = 0; t < color.size(); t++)
    {
        cout << ans[color[t].first]<<" ";
    }
    cout << endl;
    return 0;
}