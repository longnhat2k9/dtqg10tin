#include<bits/stdc++.h>
using namespace std;

int n, m;
const int md = 1e6;
vector<int> a[md];
vector<int> fr(md, 0);
bool stop = false;
long long cnt = 0;

void dfs(int j)
{
    fr[j] = 1;
    for(int i = 0; i < a[j].size(); i++)
    {
        if(fr[a[j][i]] == 0)
        {
            dfs(a[j][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("dancu.inp", "r", stdin);
    freopen("dancu.out", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        if(fr[i] == 0)
        {
            cnt++;
            dfs(i);
        }
    }

    cout << cnt << endl;

    return 0;
}