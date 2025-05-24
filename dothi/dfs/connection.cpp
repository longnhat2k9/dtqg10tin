#include<bits/stdc++.h>
using namespace std;

int n, m;
const int md = 1e6;
vector<int> a[md];
vector<int> fr(md, 0);
bool stop = false;
long long cnt = 0;
long long len = 0;
vector<int>savelen;

void exp()
{
    for(auto &x : savelen) cout << x << " ";
    cout << endl;
    savelen.erase(savelen.begin(), savelen.end());
}

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
    savelen.push_back(j);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("CONNECT.inp", "r", stdin);
    freopen("CONNECT.out", "w", stdout);

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
            len = 0;
            cnt++;
            dfs(i);
            exp();
        }
    }



    return 0;
}