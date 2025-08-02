#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("MINIMUMK.inp", "r", stdin);
	freopen("MINIMUMK.out", "w", stdout);

	long long n, m; cin >> n >> m;
	deque<pair<long long, long long>>q;
	for(long long i = 1; i <= n; i++)
	{
		while(!q.empty() && q.front().second <= i - m)
		{
			q.pop_front();
		}
		long long x; cin >> x;
		while(!q.empty() && q.back().first >= x)
		{
			q.pop_back();
		}
		q.push_back({x, i});
		if(i >= m)
		{
			cout << q.front().first << "\n";
		}
	}
}