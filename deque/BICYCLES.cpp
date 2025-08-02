#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("BICYCLES.inp", "r", stdin);
	freopen("BICYCLES.out", "w", stdout);

	long long n, m; cin >> n >> m;
	deque<long long>dq;
	for(long long i = 0; i < n; i++)
	{
		long long x; cin >> x;
		dq.push_back(x);
	}
	sort(dq.begin(), dq.end(), greater<long long>());

	long long cnt = 0;
	while(!dq.empty())
	{
		cnt++;
		if(dq.front() + dq.back() <= m && dq.size() > 1)
		{
			dq.pop_back();
		}
		dq.pop_front();
	}

	cout << cnt << "\n";
}