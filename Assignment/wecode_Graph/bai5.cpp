/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph
{
private:
    vector<vector<int>> D;
    map <string,int> ax;
    map <int,string> ay;
public:
    
    void nhap(int,int);
    void myProcess(int);
};
void Graph:: nhap(int v,int e)
{
    for (int j = 0; j < v; j++)
    {
        string a;
        cin>>a;
        ax[a] = j;
        ay[j] = a;
    }
    string x, y;
    vector<vector<int>> H(v, vector<int>(v, 0));
    D = H;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        D[ax[x]][ax[y]] = 1;
    }
}

void Graph:: myProcess(int n)
{
    int x;
    string y, z;
    for (int j = 0; j < n; j++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            if (D[ax[y]][ax[z]] == 1)
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;
        }
        else
        {
            cin >> y;
            int flag = 0;
            for (int i = 0; i < D.size(); i++)
                if (D[ax[y]][i] == 1)
                {
                    flag = 1;
                    cout<<ay[i]<<" ";
                }
            cout << endl;
            if (flag == 0)
                cout << "NONE" << endl;
        }
    }
}


int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}

