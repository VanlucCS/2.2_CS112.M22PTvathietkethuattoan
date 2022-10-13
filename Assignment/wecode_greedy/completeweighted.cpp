#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, set<string>> D;
void input(int n)
{
    string x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        D[x].insert(y);
    }
}
void complete_graph(int n)
{
    map<string, set<string>>::iterator temp;
    for (temp = D.begin(); temp != D.end(); temp++)
    {
        if (temp->second.size() != n - 1)
        {
            cout << "FALSE";
            return;
        }
    }
    cout << "TRUE";
    return;
}

int main()
{
    int n;
    cin >> n;
    input(n);
    complete_graph(D.size());
    return 0;
}
