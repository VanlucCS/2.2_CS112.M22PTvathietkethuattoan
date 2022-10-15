#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// ll abc = 0;
ld dtb = 0;
ld diem_min = 0;
ld min_diem(ld b[], ld a[], ld tbm, ll n)
{
    int min = 0;
    for (ll k = 1; k < n; k++)
        if (b[k] < b[min])
            min = k;
    ld S = tbm;
    for (ll k = 0; k < n; k++)
    {
        if (k != min)
            S -= 10 * b[k];
    }

    return roundf((S / b[min])-0.5);
}
void diem(ld b[], ld a[], ld tbm, ll n, ll i)
{

    for (ld j = diem_min; j <= 10; j = j + 0.25)
    {
        a[i] = j;
        ld diemtp = a[i] * b[i];

        if (dtb + diemtp - 0.05 > tbm)
            break;
        dtb += diemtp;
        if (i < n - 1)
            diem(b, a, tbm, n, i + 1);
        else if (roundf(dtb * 10) == tbm * 10)
        {
            for (ll o = 0; o < n; o++)
                cout << a[o] << " ";
            cout << endl;
            // abc++;
        }
        dtb -= diemtp;
    }
    return;
}

int main()
{
    ll n;
    ld tbm;
    ld b[10];
    ld a[10];
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] = b[i] / 100;
    }
    cin >> tbm;
    diem_min = min_diem(b, a, tbm, n);
    // cout<<"min:"<<diem_min<<endl;
    diem(b, a, tbm, n, 0);
    // cout<<abc;
    return 0;
}