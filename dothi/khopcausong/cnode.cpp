#include<bits/stdc++.h>
using namespace std;

int n, m;
const int mx = 1e5 + 10;
int cnt, low[mx], num[mx], khop[mx];
vector<int>ans_khop, adj[mx];
vector<pair<int, int>>ans_cau;
map<pair<int,int>, int> edge_count;

void dfs(int u, int cha)
{
	cnt++;
	num[u] = low[u] = cnt;
	int con = 0;

	for(auto &v : adj[u])
	{
		if(v == cha)
		{
			continue;
		}

		if(num[v] != 0)
		{
			low[u] = min(low[u], num[v]);
		}
		else
		{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > num[u] && edge_count[{min(u, v), max(u, v)}] == 1) 
			{
				ans_cau.push_back({min(u, v), max(u, v)});
			}
			if(low[v] >= num[u] && cha != -1)
			{
				khop[u] = 1;
			}
			con++;
		}
	}
	if(cha == -1 && con > 1)
	{
		khop[u] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("cnode.inp", "r", stdin);
	freopen("cnode.out", "w", stdout);

	cin >> n >> m;

	memset(low, 0, sizeof(low));
	memset(num, 0, sizeof(num));
	memset(khop, 0, sizeof(khop));
	cnt = 0;

	set<pair<int, int>>mp;
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		if(u == v) continue;
		if(edge_count[{min(u, v), max(u, v)}] > 1) continue; 

		mp.insert({min(u, v), max(u, v)});
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= n; i++)
	{
		if(num[i] == 0)
		{
			dfs(i, -1);
		}
	}

	for(int i = 1; i <= n; ++i) {
        if(khop[i] == 1) ans_khop.push_back(i);
    }

    sort(ans_khop.begin(), ans_khop.end());
    sort(ans_cau.begin(), ans_cau.end());

    cout << ans_khop.size()  << endl;
    // for(auto &x : ans_cau)
    // {
    // 	cout << x.first << " " << x.second << endl;
    // }
    for(auto &x : ans_khop)
    {
    	cout << x << " ";
    }
}