#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("loco.inp", "r", stdin);
    freopen("loco.out", "w", stdout);

    long long n, m;
    cin >> n >> m;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (long long i = 1; i <= n; i++) {
        if (i >= 1) {
            dp[i] = (dp[i] + dp[i - 1]) % m;
        }
        if (i >= 2) {
            dp[i] = (dp[i] + dp[i - 2]) % m;
        }
        if (i >= 3) {
            dp[i] = (dp[i] + dp[i - 3]) % m;
        }
    }

    cout << dp[n] << endl;
    return 0;
}