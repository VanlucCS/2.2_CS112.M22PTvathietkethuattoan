#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;
bool check(char s[], int n)
{
    stack<int> st;
    vector<pair<int, int>> matches;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(') // chỉ đẩy dấu ngoặc mở vào Stack
            st.push(i);
        else
        {
            if (st.empty())
                return false;                 // dãy không phải là dãy ngoặc đúng
            matches.push_back({st.top(), i}); // tìm thấy một cặp tương ứng
            st.pop();
        }
    }
    if (!st.empty())
        return false; // nếu Stack không rỗng thì dãy không đúng
    return true;
}
void capngoacdon(char S[], string c, int n, int i)
{
    for (int j = 0; j < 2; j++)
    {
        S[i] = c[j]; //gán giá ngoặc
        if (i == (n * 2 - 1))
        {
            if (check(S, n * 2))
            {
                for (int o = 0; o < n * 2; o++)
                    cout << S[o];
                cout << endl;
            }
        }
        else if (i < n * 2 - 1)
            capngoacdon(S, c, n, i + 1);
    }
    return;
}
int main()
{
    int n;
    char S[40];
    cin >> n;
    string c = "()";
    capngoacdon(S, c, n, 0);
    return 0;
}
