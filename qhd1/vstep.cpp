#include<bits/stdc++.h>
using namespace std;

const int m = 14062008;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("VSTEPS.inp", "r", stdin);
    freopen("VSTEPS.out", "w", stdout);

    long long n, k; cin >> n >> k;
    vector<long long>a(n + 1, 0);
    a[1] = 1;
    for(long long i = 0; i < k; i++)
    {
        long long x; cin >> x;
        a[x] = -1;
    }

    for(long long i = 2; i <= n; i++)
    {
        if(a[i] != -1)
        {
            a[i] = a[i - 1] + a[i - 2];
            a[i] = a[i] % m;
        }
        else
        {
            a[i] = 0;
        }
    }

    cout << a[n];
    return 0;
}