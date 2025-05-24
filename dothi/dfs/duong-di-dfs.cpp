#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int md = 1e5 + 7;
vector<int> a[md];
int n, m;
int s, t;
vector<int> fr(md, 0);
vector<int> ans;

void exp()
{
    for(auto &x : ans) cout << x << " ";
    exit(0);
}

void dfs(int j)
{
    for(int i = 0; i < a[j].size(); i++)
    {
        if(a[j][i] == t)
        {
            ans.pb(t);
            exp();
        }

        if(fr[a[j][i]] == 0)
        {
            fr[a[j][i]] = 1;
            ans.pb(a[j][i]);
            dfs(a[j][i]);
            ans.pop_back();
            // fr[a[j][i]] = 0;
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen("dfs.inp", "r", stdin);
    freopen("dfs.out", "w", stdout);
    
    cin >> n >> m;
    cin >> s >> t;

    fr[s] = 1;
    ans.pb(s);

    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        a[u].pb(v);
    }

    for(int i = 1; i <= n; i++) sort(a[i].begin(), a[i].end());
    dfs(s);

    return 0;
}