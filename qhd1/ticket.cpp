#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("NKTICK.inp", "r", stdin);
    freopen("NKTICK.out", "w", stdout);

    long long n; cin >> n;
    vector<long long>a(n);
    vector<long long>b(n - 1);
    for(long long i = 0; i < n; i++) cin >> a[i];
    for(long long i = 0; i < n - 1; i++) cin >> b[i];

    vector<long long>dp(n + 1, 0); dp[1] = a[0];
    for(long long i = 2; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + a[i - 1], dp[i - 2] + b[i - 2]);
    }

    cout << dp[n];

    return 0;
}