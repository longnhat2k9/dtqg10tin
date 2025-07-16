#include<bits/stdc++.h>
using namespace std;

struct dcm {
	long long sum, x, y;

	bool operator>(const dcm& other) const {
		return sum > other.sum;
	}
};

long long m, n, k;
priority_queue<dcm, vector<dcm>, greater<dcm>> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("kmin.inp", "r", stdin);
	freopen("kmin.out", "w", stdout);

	cin >> m >> n >> k;
	vector<long long> a(m), b(n);
	for(long long i = 0; i < m; i++) cin >> a[i];
	for(long long i = 0; i < n; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	// for(long long i = 0; i < m; i++) cout << a[i];
	// for(long long i = 0; i < n; i++) cout << b[i];

	for(long long i = 0; i < m; i++)
	{
		pq.push({a[i] + b[0], i, 0});
		// cout << a[i] + b[0] << " ";
	}

	for(long long i = 0; i < k && !pq.empty(); i++)
	{
		dcm res = pq.top();
		pq.pop();
		cout << res.sum << "\n";
		if(res.y + 1 < n) pq.push({a[res.x] +b[res.y + 1], res.x, res.y + 1});
	}

	return 0;
}