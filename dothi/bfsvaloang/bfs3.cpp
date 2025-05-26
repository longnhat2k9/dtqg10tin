#include<bits/stdc++.h>
using namespace std;

int n, m, st, nd;

const int MX = 1e6 + 10;
vector<pair<int, int>>a[MX];
vector<int>node(MX, -1);
vector<int>id(MX, -1);
queue<int>q;

void exp()
{
    vector<int>ans;
    int i = nd;
    while(node[i] != 0)
    {
        ans.push_back(id[i]);
        i = node[i];
    }
    reverse(ans.begin(), ans.end());
    
    for(auto &x: ans) cout << x << " ";
}

void bfs()
{
    while(q.size() != 0)
    {
        int x = q.front();
        for(int i = 0; i < a[x].size(); i++)
        {
            if(node[a[x][i].first] == -1)
            {
                node[a[x][i].first] = x;
                id[a[x][i].first] = a[x][i].second;
                if(a[x][i].first == nd) exp();
                q.push(a[x][i].first);
            }
        }
        q.pop();
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("BFS3.inp", "r", stdin);
    freopen("BFS3.out", "w", stdout);

    cin >> n >> m >> st >> nd;
    for(int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(make_pair(y, i));
    }
    node[st] = 0; id[st] = 0; q.push(st);
    for(int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
    }
    
    bfs();
        
    return 0;
}