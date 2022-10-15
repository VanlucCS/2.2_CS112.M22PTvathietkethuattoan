#include <iostream>
using namespace std;

typedef long long ll;


int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;
	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được
    
    
    G = new bool *[v];
    for (int i = 0; i < v; i++)
        G[i] = new bool(v);
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            G[i][j] = 0;
    inputGraph(G,e);
    process(G,v,n);
    for(int i = 0; i < v; i++)
        delete []G[i];
    delete []G;
}
void inputGraph(bool* G[], int e)
{
	long x,y;
	for (int i = 0; i < e; i++)
		{
			cin >> x >> y;
			G[x - 1][y - 1] = 1;
		}
}
void process(bool* G[] , int v , int n)
{
	long x,y,z;
	for (int j = 0; j < n; j++)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            if (G[y - 1][z - 1] == 1)
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;
        }
        else
        {
            cin >> y;
            int flag = 0;
            for (int i = 0; i < v; i++)
                if (G[y - 1][i] == 1)
                {
                    flag = 1;
                    cout << i + 1 << " ";
                }
            cout << endl;
            if (flag == 0)
                cout << "NONE" << endl;
        }
    }
}