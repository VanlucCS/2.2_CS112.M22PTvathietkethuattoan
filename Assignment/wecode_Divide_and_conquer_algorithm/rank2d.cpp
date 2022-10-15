#include <iostream>
using namespace std;
int R[5] = {0};

void Rank(int S[5], int n, int l, int r)
{
    if (l == r || n == 0)
        return;
    int mid = (l + r) / 2;
    Rank(S, n/2, l, mid);
    Rank(S, n/2, mid + 1, r);
    for (int i = mid + 1; i <= r; i++)
        for (int j = 0; j <= mid; j++)
            if (S[i] > S[j]) // tung do lon hon
                R[i]++;
}
int main()
{
    int S[5] = {2, 4, 3, 5, 1};
    Rank(S, 5, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << R[i];
    return 0;
}