#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> &x, pair<long long, long long> &y)
{
	return x.second < y.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("coupons.inp", "r", stdin);
	freopen("coupons.out", "w", stdout);

	long long n, k, m; cin >> n >> k >> m;

	vector<pair<long long, long long>>a(n);

	for(long long i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end(), cmp);

	long long cnt = 0, money = 0;
	priority_queue<long long, vector<long long>, greater<long long>>pq;
	for(long long i = 0; i < n; i++)
	{
		if(k > 0)
		{
			cnt++;
			money += a[i].second;
			// cout << money << endl;
			if(money > m) 
			{
				cnt--;
				money -= a[i].second;
			}
			else
			{
				pq.push(a[i].first - a[i].second);
				k--;
			}
		}
		else
		{
			if(a[i].second + pq.top() < a[i].first)
			{
				money += a[i].second + pq.top();
				// cout << money << endl;
				if(money <= m)
				{
					pq.pop();
					pq.push(a[i].first - a[i].second);
				}
				else
				{
					money -= a[i].second + pq.top();
					cnt--;
				}
			}
			else
			{
				money += a[i].first;
				// cout << money << endl;
				if(money > m)
				{
					cnt--;
					money -= a[i].first;
				}
			}
			cnt++;
		}
	// cout << money << " " << m << endl;
	}

	if(money > m) cnt--;
	cout << cnt << "\n";
}