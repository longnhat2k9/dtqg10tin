#include<bits/stdc++.h>
using namespace std;

long long n, m;
const long long mx = 1e5 + 10;
long long lab[mx];

long long findset(long long u)
{
	return lab[u] < 0 ? u : lab[u] = findset(lab[u]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("dsf.inp", "r", stdin);
	freopen("dsf.out", "w", stdout);

	memset(lab, -1, sizeof(lab));

	cin >> n >> m;
	for(long long i = 0; i < m; i++)
	{
		long long u, v; cin >> u >> v;
		long long r = findset(u), s = findset(v);

		if(r != s)
		{
			if(lab[s] < lab[r])
			{
				swap(s, r);
			}

			lab[r] += lab[s];
			lab[s] = r;
			n--;
		}
		cout << n << endl;
	}
}