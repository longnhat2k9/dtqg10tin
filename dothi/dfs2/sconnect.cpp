#include<bits/stdc++.h>
using namespace std;

long long n, m;
const long long mx = 100005;
vector<long long>goc[mx], biendoi[mx];
stack<long long> st;
vector<long long>vs(mx, 0);
vector<long long>ans;

void dfs1(long long u) {
	vs[u] = 1;
	for(auto v : goc[u])
	{
		if(vs[v] == 0) {
			dfs1(v);
		}
	}
	st.push(u);
}

void dfs2(long long u) {
	vs[u] = 1;
	ans.push_back(u);
	for(auto v : biendoi[u]) {
		if(vs[v] == 0) {
			dfs2(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("sconnect.inp", "r", stdin);
	freopen("sconnect.out", "w", stdout);

	cin >> n >> m;

	for(long long i = 0; i < m; i++) {
		long long u, v; cin >> u >> v;
		goc[u].push_back(v);
		biendoi[v].push_back(u);
	}

	for(long long i = 1; i <= n; i++) {
		if(vs[i] == 0)
		{
			dfs1(i);
		}
	}

	fill(vs.begin(), vs.end(), 0);

	while(!st.empty()) {
		long long u = st.top();
		st.pop();

		if(vs[u] == 0) {
			dfs2(u);

			for(auto x : ans) {
				cout << x << " ";
			}
			ans.clear();
			cout << "\n";
		}
	}
}