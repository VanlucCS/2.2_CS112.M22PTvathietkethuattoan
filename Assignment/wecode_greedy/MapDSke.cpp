#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
map<string, vector<string>> Graph;
vector<vector<int>> M;
vector<string> ans;
map<string, int> ax;

void input(int v,int e)
{
    for (int j = 0; j < v; j++)
    {
        string a;
        cin >> a;
        ans.push_back(a);
        ax[a] = j;
    }
    vector<vector<int>> H(v, vector<int>(v, 0));
    M =H;
    string x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
        M[ax[x]][ax[y]] = 1;
        M[ax[y]][ax[x]] = 1;
    }

}

void Degreeofertices()
{
    map<string, vector<string>>::iterator temp;

    for (int i =0 ;i<ans.size();i++)
    {
        cout<<Graph[ans[i]].size()<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    int v, e;
    cin >> v >> e;
    input(v, e);
    Degreeofertices();
    return 0;
}
