#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int md = 1e3 + 7;
vector<int> a[md];
int n, m;
vector<int> fr(md, 0);

void dfs(int j)
{
    for(int i = 0; i < a[j].size(); i++)
    {
        if(a[j][i] == n)
        {
            cout << "YES" << endl;
            exit(0);
        }

        if(fr[a[j][i]] == 0)
        {
            fr[a[j][i]] = 1;
            dfs(a[j][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen("DFS0.inp", "r", stdin);
    freopen("DFS0.out", "w", stdout);
    
    cin >> n >> m;

    fr[1] = 1;

    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    for(int i = 1; i <= n; i++) sort(a[i].begin(), a[i].end());
    dfs(1);
    cout << "NO" << endl;

    return 0;
}