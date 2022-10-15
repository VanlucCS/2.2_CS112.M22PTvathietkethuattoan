#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld dtb=0;
void diem(ld b[], ld a[], ld tbm, ll n, ll i)
{
    for (ld j = 0.25; j <= 10; j = j + 0.25)
    {
        a[i] = j;
		ld diemtp = a[i] * b[i];

		if (dtb + diemtp - 0.05> tbm)
			break;
		dtb += diemtp;
		if (i < n - 1)
			diem(b, a, tbm, n, i + 1);
		else if (roundf(dtb * 10) ==  tbm *10)
        {
			for (ll o = 0; o < n; o++)
                    cout << a[o] << " ";
                cout << endl;
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
    diem(b, a, tbm, n, 0);
    return 0;
}