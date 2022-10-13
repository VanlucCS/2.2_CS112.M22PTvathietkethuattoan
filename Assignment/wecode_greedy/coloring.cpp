#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
map<string, vector<string>> Graph;
vector<pair<string, int>> color;
map<string, int> M;
map<string, vector<string>> constraint;
set<int> mau;
void input(int v, int e)
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
    for (int j = 0; j < v; j++)
    {
        int a;
        cin >> a;
        color[j].second = a;
        M[color[j].first] = a;
        if (a != -1)
        {
            mau.insert(a);
            for (int i = 0; i < Graph[color[j].first].size(); i++)
            {
                constraint[Graph[color[j].first][i]].push_back(color[j].first);
            }
        }
    }
}

void coloring()
{
    string dinh;
    cin >> dinh;
    int flag = 0;
    if (M[dinh] != -1) // neu da to
    {
        int a[10] = {0};
        for (int i = 1; i < constraint[dinh].size(); i++)
        {
            if (M[dinh] == M[constraint[dinh][i]])
                flag = 1;
            a[M[constraint[dinh][i]]] = 1;
        }
        if (flag == 0)
        { // neu to dung ko trung voi dinh rang buoc
            cout << "TRUE" << endl;
            return;
        }
        else // to sai
        {
            // to lai ma
            set<int>::iterator itr;
            for (itr = mau.begin(); itr != mau.end(); itr++)
            {

                if (a[*itr] == 0)
                {
                    cout << *itr << endl;
                    return;
                }
            }
            int k = 0;
            while (1)
            { // tim mau phu hop
                if (a[k] == 0)
                    break;
                k++;
            }
            cout << k << endl;
        }
    }
    else
    {
        int a[10] = {0};
        for (int i = 1; i < constraint[dinh].size(); i++)
            a[M[constraint[dinh][i]]] = 1; // bo qua mau bi rang buoc
        set<int>::iterator itr;
        for (itr = mau.begin(); itr != mau.end(); itr++)
        {
            if (a[*itr] == 0)
            {
                cout << *itr << endl;
                return;
            }
        }
        int k = 0;
        while (1)
        { // tim mau phu hop
            if (a[k] == 0)
                break;
            k++;
        }

        cout << k << endl;
    }
    return;
}

int main()
{
    int v, e, n;
    cin >> v >> e >> n;
    input(v, e);
    for (int i = 0; i < n; i++)
        coloring();
    cout << endl;
    return 0;
}