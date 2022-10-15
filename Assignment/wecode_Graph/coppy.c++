#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph
{
private:a
    vector<vector<int>> D;
    map <char,int> ax;
public:
    
    void nhap(int,int);
    void myProcess(int);
};
void Graph:: nhap(int v,int e)
{
    for (int j = 0; j < v; j++)
    {
        char a;
        cin>>a;
        ax[a] = j;
    }
    char x, y;
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
    char y, z;
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
                    for(auto it : ax) 
                    { 
                        if(it.second == i) 
                        { 
                            cout<< it.first << " "; 
                        } 
                    } 
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

