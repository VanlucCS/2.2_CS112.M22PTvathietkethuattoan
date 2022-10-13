#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
map<string, set<pair<string, int>>> D;
void input(int n)
{
    string x, y;
    int z;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        D[x].insert({y, z});
    }
}
int check(string a, string b)
{
    for (pair<string, int> i : D[a])
        if (i.first == b)
            return i.second;
    return -1;
}
void iscycle()
{
    vector<string> G;
    string str;
    cin>> str;
    G.push_back(str);
    while(str[0]!='.')
    {
        cin>>str;
        G.push_back(str);
    }
    int sum_length = 0;
    for (int i = 1; i < G.size() -1 ; i ++)
    {
        int v = check(G[i - 1], G[i]);
        if (v != -1)
            sum_length += v;
        else
        {
            cout << "FALSE" << endl;
            return;
        }
    }
    cout << sum_length << endl;
    return;
}

int main()
{
    int n, k;
    cin >> n >> k;
    input(n);

    for (int i = 0; i < k; i++)
        iscycle();
    return 0;
}
