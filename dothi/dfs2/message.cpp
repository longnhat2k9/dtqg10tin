#include<bits/stdc++.h>
using namespace std;

int n, m; 
const int mx = 1e5 + 10;
vector<int> fwd[mx], rev[mx];
vector<int>vs(mx);
vector<int>start;
vector<int>lb(mx, 0);
stack<int>st;
vector<set<int>>newfwd(mx);
vector<int>cntcanh(mx, 0);

void dfs1(int u)
{
    vs[u] = 1;
    for(auto &x : fwd[u])
    {
        if(vs[x] == 0)
        {
            dfs1(x);
        }
    }
    st.push(u);
}

void dfs2(int u, int label)
{
    lb[u] = label;
    vs[u] = 1;
    for(auto &v : rev[u])
    {
        if(lb[v] == 0)
        {
            dfs2(v, label);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("message.inp", "r", stdin);
    freopen("message.out", "w", stdout);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        fwd[u].push_back(v);
        rev[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        if(vs[i] == 0)
        {
            dfs1(i);
        }
    }

    int cnt = 0;
    while(!st.empty())
    {
        int u = st.top();
        st.pop();
        if(lb[u] == 0) {
            cnt++;
            dfs2(u, cnt);
            start.push_back(u);
        }
    }

    for(int u = 1; u <= n; u++)
    {
        for(auto &v: fwd[u])
        {
            if(lb[u] != lb[v] && !newfwd[lb[u]].count(lb[v])) 
            {
                newfwd[lb[u]].insert(lb[v]);
                cntcanh[lb[v]]++;
            }
        }
    }

    vector<int>ans;
    for(int i = 1; i <= cnt; i++)
    {
        if(cntcanh[i] == 0)
        {
            ans.push_back(start[i - 1]);
        }
    }

    cout << ans.size() << endl;
    for(auto &x : ans) cout << x << " ";
}