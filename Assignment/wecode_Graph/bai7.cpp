#include <iostream>
#include <map>
#include <set>
using namespace std;

class Graph
{
private:
    map<string, set<string>> D;
public:
    void nhap(int);
    bool check(string,string);
    void myProcess(int);
};
void Graph::nhap(int e)
{
    string x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        D[x].insert(y);
    }
}
bool Graph::check(string a,string b)
{
    for (string i: D[a])
        if(i == b)
            return true;
    return false;
 
}
void Graph::myProcess(int n)
{
    int x;
    string y, z;
    for (int j = 0; j < n; j++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            if (check(y,z))
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;
        }
        else
        {
            cin >> y;
            if (!D[y].empty())
            {
                int sum = 0;
                for (string x: D[y]) 
                    sum++;
                cout<<sum;
            }
            else
                cout<< 0;
            cout << endl;
        }
    }
}

int main()
{
    Graph G;
    int e, n;
    cin >> e >> n;
    G.nhap(e);
    G.myProcess(n);
    return 0;
}
