#include<bits/stdc++.h>
using namespace std;

long long n, m; 
priority_queue<long long, vector<long long>, greater<long long>>pq;
unordered_map<long long, long long>cnt;
vector<long long>a(1e6);

void cs1()
{
	long long x, k; cin >> x >> k;
	x--;
	if(a[x] > 0) cnt[a[x]]--;
	a[x] = k;
	if(k > 0) pq.push(k), cnt[k]++;
}

void cs2()
{
	while(pq.size() > 0 && cnt[pq.top()] == 0)
	{
		pq.pop();
	}
	if(pq.size() > 0) cout << pq.top() << "\n";
	else cout << "0 \n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	freopen("listman.inp", "r", stdin);
	freopen("listman.out", "w", stdout);

	cin >> n >> m;

	for(long long i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] > 0)
		{
			cnt[a[i]]++;
			pq.push(a[i]);
		}
	}

	for(long long i = 0; i < m; i++)
	{
		char x; cin >> x;
		if(x == 'S') cs1();
		else cs2();
	}

	return 0;
}