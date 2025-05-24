#include<bits/stdc++.h>
using namespace std;

const int m = 14062008;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("INCSEQ.inp", "r", stdin);
    freopen("INCSEQ.out", "w", stdout);

    long long n; cin >> n;
    vector<long long>a(n, 1);
    vector<long long>b(n, 1);
    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long mx = 0;
    for(long long i = 0; i < n; i++)
    {
        for(long long j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                b[i] = max(b[i], b[j] + 1);
                mx = max(b[i], mx);
            }
        }
    }

    cout << mx << endl;
    return 0;
}