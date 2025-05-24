#include<bits/stdc++.h>
using namespace std;

const int m = 14062008;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("LIQ.inp", "r", stdin);
    freopen("LIQ.out", "w", stdout);

    long long n; cin >> n;
    vector<long long>a(n, 1);
    vector<long long>b(n, 1);
    vector<long long>c(n, -1);
    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long mx = 0, lc = 0;
    for(long long i = 0; i < n; i++)
    {
        for(long long j = 0; j < i; j++)
        {
            if(a[j] < a[i])
            {
                if(b[i] < b[j] + 1)
                {
                    c[i] = j;
                    b[i] = b[j] + 1;
                }
                if(b[i] > mx)
                {
                    mx = b[i];
                    lc = i;
                }
            }
        }
    }

    cout << mx << endl;
    vector<long long>ans(mx);
    for(long long i = 0; i < mx; i++)
    {
        ans[i] = lc;
        lc = c[lc];
    }
    sort(ans.begin(), ans.end());
    for(auto &x : ans)
    {
        cout << x + 1 << " ";
    }
    return 0;
}