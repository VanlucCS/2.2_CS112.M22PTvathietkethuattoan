/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

void inputGraph(vector<vector<int>> &G, int v, int e)
{
    long x, y;
    vector<vector<int>> D(v, vector<int>(v, 0));
    G = D;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        G[x - 1][y - 1] = 1;
        G[y - 1][x - 1] = 1;
    }
}
void process(vector<vector<int>> &G, int v, int n)
{
    long x, y, z;
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
// int main()
// {

//     int v, e, n;
//     cin >> v >> e >> n; // v: số đỉnh, e: số cạnh, n: số thao tác
//     vector<vector<int>> G(v, vector<int>(v, 0));

//     inputGraph(G, v, e);
//     process(G, v, n);

//     return 0;
// }


int main()
{

	int v, e, n;
	cin >> v >> e >> n; //v: số đỉnh, e: số cạnh, n: số thao tác
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}
