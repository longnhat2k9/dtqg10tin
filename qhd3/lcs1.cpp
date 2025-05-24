#include<bits/stdc++.h>
using namespace std;

int n, m, f[10000][10000];
string a, b;
string ans = "";

int main()  
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen("LCS1.inp", "r", stdin);
    freopen("LCS1.out", "w", stdout);
    
    cin >> a >> b;
    n = a.size(), m = b.size();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i - 1] == b[j - 1]) 
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }

    while(n && m) {
        if(a[n - 1] == b[m - 1]) {
            ans += a[n - 1];
            n--;
            m--;
        }
        else if(f[n - 1][m] > f[n][m - 1]) n--;
        else m--;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}